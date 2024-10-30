import yfinance as yf
import pandas as pd
from datetime import datetime, timedelta
from telegram import Update
from telegram.ext import Application, CommandHandler, CallbackContext
import matplotlib.pyplot as plt
from io import BytesIO
import mplfinance as mpf
import locale
import numpy as np

TELEGRAM_TOKEN = 'YOUR_TELEGRAM_BOT_TOKEN'
CHAT_ID = 'YOUR_CHAT_ID'
whitelisted_users = {1400159370, 777000, 1837418281}
user_last_command_time = {}

def calculate_ema(prices, period):
    return prices.ewm(span=period, adjust=False).mean()

def calculate_macd(df):
    df['EMA_12'] = calculate_ema(df['Close'], 12)
    df['EMA_26'] = calculate_ema(df['Close'], 26)
    df['MACD'] = df['EMA_12'] - df['EMA_26']
    df['MACD_Signal'] = calculate_ema(df['MACD'], 9)
    return df

def calculate_rsi(df, period=14):
    delta = df['Close'].diff()
    gain = delta.where(delta > 0, 0).rolling(window=period, min_periods=1).mean()
    loss = -delta.where(delta < 0, 0).rolling(window=period, min_periods=1).mean()
    rs = gain / loss
    df['RSI'] = 100 - (100 / (1 + rs))
    return df

def apply_ema_strategy(df, short_period, long_period):
    df['EMA_Short'] = calculate_ema(df['Close'], short_period)
    df['EMA_Long'] = calculate_ema(df['Close'], long_period)
    return df

def apply_strategies(df, short_period, long_period):
    df = apply_ema_strategy(df, short_period, long_period)
    df = calculate_macd(df)
    df = calculate_rsi(df)
    df['Buy_Signal_EMA'] = ((df['EMA_Short'] > df['EMA_Long']) & 
                            (df['EMA_Short'].shift(1) <= df['EMA_Long'].shift(1))).fillna(False)
    df['Sell_Signal_EMA'] = ((df['EMA_Short'] < df['EMA_Long']) & 
                             (df['EMA_Short'].shift(1) >= df['EMA_Long'].shift(1))).fillna(False)
    df['Buy_Signal_MACD'] = ((df['MACD'] > df['MACD_Signal']) & 
                             (df['MACD'].shift(1) <= df['MACD_Signal'].shift(1))).fillna(False)
    df['Sell_Signal_MACD'] = ((df['MACD'] < df['MACD_Signal']) & 
                              (df['MACD'].shift(1) >= df['MACD_Signal'].shift(1))).fillna(False)
    df['Buy_Signal_RSI'] = (df['RSI'] < 30).fillna(False)
    df['Sell_Signal_RSI'] = (df['RSI'] > 70).fillna(False)
    return df

def get_last_signal(df, signal_column):
    signal_rows = df[df[signal_column]].tail(1)
    if not signal_rows.empty:
        last_signal_date = signal_rows.index[-1].strftime('%Y-%m-%d')
        last_signal_price = signal_rows['Close'].iloc[-1]
        return last_signal_date, last_signal_price
    return None, None

def get_last_signals(df):
    last_buy_ema_date, last_buy_ema_price = get_last_signal(df, 'Buy_Signal_EMA')
    last_sell_ema_date, last_sell_ema_price = get_last_signal(df, 'Sell_Signal_EMA')
    last_buy_macd_date, last_buy_macd_price = get_last_signal(df, 'Buy_Signal_MACD')
    last_sell_macd_date, last_sell_macd_price = get_last_signal(df, 'Sell_Signal_MACD')
    last_buy_rsi_date, last_buy_rsi_price = get_last_signal(df, 'Buy_Signal_RSI')
    last_sell_rsi_date, last_sell_rsi_price = get_last_signal(df, 'Sell_Signal_RSI')
    return (last_buy_ema_date, last_buy_ema_price, last_sell_ema_date, last_sell_ema_price,
            last_buy_macd_date, last_buy_macd_price, last_sell_macd_date, last_sell_macd_price,
            last_buy_rsi_date, last_buy_rsi_price, last_sell_rsi_date, last_sell_rsi_price)

def calculate_pivot_support_resistance(df):
    high = df['High'].iloc[-1]
    low = df['Low'].iloc[-1]
    close = df['Close'].iloc[-1]
    pivot = (high + low + close) / 3
    resistance_1 = 2 * pivot - low
    resistance_2 = pivot + (high - low)
    support_1 = 2 * pivot - high
    support_2 = pivot - (high - low)
    return pivot, support_1, support_2, resistance_1, resistance_2

def plot_candlestick_chart(df, support_1, support_2, resistance_1, resistance_2):
    try:
        locale.setlocale(locale.LC_TIME, 'Turkish_Turkey.1254')
    except locale.Error:
        print("Türkçe yerel ayarı bulunamadı. Varsayılan ayarlar kullanılacak.")
    df = df[-15:]
    df.index = pd.to_datetime(df.index)
    buy_signals = df[(df['Buy_Signal_EMA'].fillna(False)) | (df['Buy_Signal_MACD'].fillna(False)) | (df['Buy_Signal_RSI'].fillna(False))]
    sell_signals = df[(df['Sell_Signal_EMA'].fillna(False)) | (df['Sell_Signal_MACD'].fillna(False)) | (df['Sell_Signal_RSI'].fillna(False))]
    buy_signals = buy_signals.reindex(df.index).fillna(np.nan)
    sell_signals = sell_signals.reindex(df.index).fillna(np.nan)
    add_buy_signals = [
        mpf.make_addplot(buy_signals['Close'], type='scatter', marker='^', color='green', markersize=100, label='Al')]
    add_sell_signals = [
        mpf.make_addplot(sell_signals['Close'], type='scatter', marker='v', color='red', markersize=100, label='Sat')]
    fig, ax = mpf.plot(
        df,
        type='candle',
        style='charles',
        title='Son 15 Gün Kapanış Fiyatı',
        ylabel='Fiyat',
        datetime_format='%d %B %Y',
        addplot=add_buy_signals + add_sell_signals,
        returnfig=True
    )
    ax[0].text(0.5, 0.95, 'İNCİ BOT', fontsize=14, ha='center', va='top', transform=ax[0].transAxes)
    ax[0].axhline(y=support_1, color='green', linestyle='--', label='Destek 1')
    ax[0].axhline(y=support_2, color='green', linestyle='--', label='Destek 2')
    ax[0].axhline(y=resistance_1, color='red', linestyle='--', label='Direnç 1')
    ax[0].axhline(y=resistance_2, color='red', linestyle='--', label='Direnç 2')
    ax[0].text(0.1, support_1, f'{support_1:.2f}', ha='left', va='bottom', color='green', fontsize=10)
    ax[0].text(0.1, support_2, f'{support_2:.2f}', ha='left', va='bottom', color='green', fontsize=10)
    ax[0].text(0.1, resistance_1, f'{resistance_1:.2f}', ha='left', va='bottom', color='red', fontsize=10)
    ax[0].text(0.1, resistance_2, f'{resistance_2:.2f}', ha='left', va='bottom', color='red', fontsize=10)
    ax[0].legend()
    plt.show()

def get_realtime_signals(symbol, short_period, long_period):
    try:
        df = yf.download(symbol, period="1y", interval="1d")
        if df.empty:
            return f"{symbol} için veri bulunamadı."
        current_price = df['Close'].iloc[-1]
        df = apply_strategies(df, short_period, long_period)
        last_row = df.iloc[-1]

        ema_signal = 'Bekle'
        if last_row['Buy_Signal_EMA']:
            ema_signal = 'Al'
        elif last_row['Sell_Signal_EMA']:
            ema_signal = 'Sat'

        macd_signal = 'Bekle'
        if last_row['Buy_Signal_MACD']:
            macd_signal = 'Al'
        elif last_row['Sell_Signal_MACD']:
            macd_signal = 'Sat'

        rsi_signal = 'Bekle'
        if last_row['Buy_Signal_RSI']:
            rsi_signal = 'Al'
        elif last_row['Sell_Signal_RSI']:
            rsi_signal = 'Sat'

        (last_buy_ema_date, last_buy_ema_price, last_sell_ema_date, last_sell_ema_price,
         last_buy_macd_date, last_buy_macd_price, last_sell_macd_date, last_sell_macd_price,
         last_buy_rsi_date, last_buy_rsi_price, last_sell_rsi_date, last_sell_rsi_price) = get_last_signals(df)

        pivot, support_1, support_2, resistance_1, resistance_2 = calculate_pivot_support_resistance(df)

        message = (
            f"{symbol} - Şu anki fiyat: {current_price:.2f} \n\n"
            f"{symbol} - Bugün:\n"
            f"Sinyal 1: {ema_signal}\n"
            f"Sinyal 2: {macd_signal}\n"
            f"Sinyal 3: {rsi_signal}\n\n"
            f"{symbol} - En Son Sinyaller:\n"
            f"Sinyal 1\n AL: {last_buy_ema_date}, Fiyat: {last_buy_ema_price:.2f} / Sat: {last_sell_ema_date}, Fiyat: {last_sell_ema_price:.2f}\n"
            f"Sinyal 2\n AL: {last_buy_macd_date}, Fiyat: {last_buy_macd_price:.2f} / Sat: {last_sell_macd_date}, Fiyat: {last_sell_macd_price:.2f}\n"
            f"Sinyal 3\n AL: {last_buy_rsi_date}, Fiyat: {last_buy_rsi_price:.2f} / Sat: {last_sell_rsi_date}, Fiyat: {last_sell_rsi_price:.2f}\n\n"
            f"Pivot Noktası: {pivot:.2f}\n"
            f"Destek 1: {support_1:.2f}, Destek 2: {support_2:.2f}\n"
            f"Direnç 1: {resistance_1:.2f}, Direnç 2: {resistance_2:.2f}"
        )

        buf = BytesIO()
        plot_candlestick_chart(df, support_1, support_2, resistance_1, resistance_2)
        plt.savefig(buf, format='png')
        buf.seek(0)
        plt.close()
        return message, buf

    except Exception as e:
        return str(e)

def check_user_limit(user_id):
    if user_id in whitelisted_users:
        return None
    current_time = datetime.now()
    if user_id in user_last_command_time:
        last_time = user_last_command_time[user_id]
        if current_time - last_time < timedelta(days=1):
            remaining_time = timedelta(days=1) - (current_time - last_time)
            hours, remainder = divmod(remaining_time.seconds, 3600)
            minutes, _ = divmod(remainder, 60)
            return f"Komutu tekrar çalıştırmak için {hours} saat {minutes} dakika beklemelisiniz."
    user_last_command_time[user_id] = current_time

async def start(update: Update, context: CallbackContext) -> None:
    user_id = update.effective_user.id
    await update.message.reply_text(f"Bot çalışıyor... Kullanıcı kimliğiniz: {user_id}")

async def tarama(update: Update, context: CallbackContext) -> None:
    user_id = update.effective_user.id
    limit_message = check_user_limit(user_id)
    if limit_message:
        await update.message.reply_text(limit_message)
        return
    args = context.args
    short_period = 4
    long_period = 8
    if args:
        symbol = args[0]
        result = get_realtime_signals(symbol, short_period, long_period)
        if isinstance(result, tuple):
            message, plot = result
            await context.bot.send_message(chat_id=CHAT_ID, text=message)
            await context.bot.send_photo(chat_id=CHAT_ID, photo=plot)
        else:
            await update.message.reply_text(result)
    else:
        await update.message.reply_text("Lütfen bir hisse sembolü girin. Örneğin: /tarama THYAO.IS")

def main():
    application = Application.builder().token(TELEGRAM_TOKEN).build()
    application.add_handler(CommandHandler('start', start))
    application.add_handler(CommandHandler('tarama', tarama))
    application.run_polling()

if __name__ == '__main__':
    main()
