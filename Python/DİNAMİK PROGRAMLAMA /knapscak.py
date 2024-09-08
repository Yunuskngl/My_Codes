def hesapla(agirliklar, degerler, indeks, kapasite, dp):
    # Eğer tüm ürünler gözden geçirildiyse veya çanta kapasitesi dolduysa
    if indeks == n or kapasite == 0:
        return 0  # Artık daha fazla ürün eklenemez, bu yüzden değer 0 olur

    # Eğer bu durumu daha önce hesapladıysak, önceden hesaplanan değeri döndür
    if dp[indeks][kapasite] != 0:
        return dp[indeks][kapasite]

    # Ürünü dahil etmeme durumu: bir sonraki ürünü değerlendirmek için fonksiyonu çağır
    sonuc = hesapla(agirliklar, degerler, indeks + 1, kapasite, dp)
    
    # Eğer mevcut ürün çantaya sığabiliyorsa, ürünü dahil etme seçeneğini değerlendir
    if agirliklar[indeks] <= kapasite:
        # Ürünü dahil etme durumu: bu ürünü dahil ederek en yüksek değeri bul
        sonuc = max(sonuc, hesapla(agirliklar, degerler, indeks + 1, kapasite - agirliklar[indeks], dp) + degerler[indeks])

    # Hesaplanan değeri dp tablosuna kaydet (dinamik programlama tablosu)
    dp[indeks][kapasite] = sonuc
    
    # Mevcut indeks ve kapasite için maksimum değeri döndür
    return sonuc


n = int(input("Ürün sayısını girin: "))
maks_agirlik = int(input("Maksimum ağırlığı girin: "))

agirliklar = [0] * n
degerler = [0] * n

for i in range(n):
    agirliklar[i] = int(input(f"{i+1}. ürünün ağırlığını girin: "))
    degerler[i] = int(input(f"{i+1}. ürünün değerini girin: "))

dp = [[0] * (maks_agirlik + 1) for _ in range(n)]
maks_deger = hesapla(agirliklar, degerler, 0, maks_agirlik, dp)
print(f"Maksimum değer: {maks_deger}")

#item weights = 40 10 20 24
#item values = 280 100 120 120
#max weight = 60


