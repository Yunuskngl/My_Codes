/*Murat Biberovic ve Haşim, matematik ve finans konularında tutkulu iki dahidir ve zengin olmayı hayal etmektedirler. Murat, "Arabalar" filmindeki Lightning McQueen adlı arabayı gerçek hayatta sahip olmayı hayal ederken, Haşim ise sakin bir adaya sahip olup orada kod yazmak istemektedir.

Bir akşam kahve içerken, "Dinamik Momentum Endeksi" (DMI) fikrini buldular. Geleneksel göstergelerden (örneğin RSI) farklı olarak DMI, son fiyat hareketlerine göre hesaplamalarını adapte eder, böylece piyasalardaki ani değişimlere daha duyarlı olur.

Göreviniz, Murat ve Haşim'e DMI göstergesini hesaplamalarında yardımcı olmaktır. DMI göstergesini bir dizi hisse senedi fiyatından hesaplayacak ve belirli hisse senedi ile ilgili alınması gereken aksiyonları belirleyecek bir program yazmanız gerekmektedir. Program, büyük veri setlerini işleyebilecek kadar verimli olmalıdır.

DMI'nin Hesaplanması:

Verilenler:

𝑘
k — pencerenin boyutu.
𝑝
𝑟
𝑖
𝑐
𝑒
𝑠
prices — uzunluğu 
𝑛
n olan hisse senedi fiyatları dizisi.
𝑚
m — DMI'nin hesaplanacağı gün.
DMI Hesaplama Adımları:

Son 
𝑘
k gün içerisindeki 'kazançlar toplamı' ve 'kayıplar toplamı'nı hesaplayın:

sum of gains
=
∑
𝑖
=
𝑚
−
𝑘
+
2
𝑚
max
⁡
(
0
,
𝑝
𝑟
𝑖
𝑐
𝑒
𝑠
[
𝑖
]
−
𝑝
𝑟
𝑖
𝑐
𝑒
𝑠
[
𝑖
−
1
]
)
sum of gains=∑ 
i=m−k+2
m
​
 max(0,prices[i]−prices[i−1])
sum of losses
=
∑
𝑖
=
𝑚
−
𝑘
+
2
𝑚
max
⁡
(
0
,
𝑝
𝑟
𝑖
𝑐
𝑒
𝑠
[
𝑖
−
1
]
−
𝑝
𝑟
𝑖
𝑐
𝑒
𝑠
[
𝑖
]
)
sum of losses=∑ 
i=m−k+2
m
​
 max(0,prices[i−1]−prices[i])
İlgili gün için DMI'yi hesaplayın:

DMI
𝑚
=
100
×
sum of gains
sum of gains
+
sum of losses
DMI 
m
​
 =100× 
sum of gains+sum of losses
sum of gains
​
 
Günlük DMI değerini hesapladıktan sonra:

Eğer DMI değeri 35'ten küçükse, '1' sinyali.
Eğer DMI değeri 65'ten büyükse, '2' sinyali.
Diğer durumlarda, '0' sinyali.
Notlar:

Eğer 'sum of gains' + 'sum of losses' sıfıra eşitse, DMI skoru 0 olacaktır.
DMI değerini yuvarlamak için Python'da :.1f formatını kullanın.
Girdi Formatı:

İlk satırda iki tam sayı 
𝑛
n ve 
𝑘
k — hisse senedi fiyatlarının sayısı ve pencerenin boyutu.
İkinci satırda 
𝑛
n tam sayı — hisse senedi fiyatları.
Çıktı Formatı:

𝑛
−
𝑘
+
1
n−k+1 satır yazdırın, her satır ilgili gün 
𝑚
m için DMI değerini ve sinyali içermelidir, 
𝑘
k gününden başlayarak 
𝑛
n gününe kadar.
Kısıtlar:

1
≤
𝑛
≤
1
0
6
1≤n≤10 
6
 
1
≤
𝑘
≤
𝑛
1≤k≤n
1
≤
𝑝
𝑟
𝑖
𝑐
𝑒
𝑠
𝑖
≤
1
0
9
1≤prices 
i
​
 ≤10 
9
 
Örnek Girdi 1:

Kodu kopyala
10 3
10 12 11 13 10 9 14 16 15 17
Örnek Çıktı 1:

Kodu kopyala
66.7 2
66.7 2
40.0 0
0.0 1
83.3 2
100.0 2
66.7 2
66.7 2*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;


double DMI(int m, int k, vector<int> prices) {
    int sum_of_gains = 0;
    int sum_of_losses = 0;
    for (int i = m - k + 1; i < m; i++) {
        if (prices[i] > prices[i - 1]) {
            sum_of_gains += prices[i] - prices[i - 1];
        } else {
            sum_of_losses += prices[i - 1] - prices[i];
        }
    }
    double DMI = 100.0 * sum_of_gains / (sum_of_gains + sum_of_losses);
    if (sum_of_gains + sum_of_losses == 0) {
        DMI = 0;
    }
    return DMI;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    
    for (int m = k; m <= n; m++) {
        double dmi = DMI(m, k, prices);
        if (dmi < 35) {
            cout << fixed << setprecision(1) << dmi << " 1" << endl;
        } else if (dmi > 65) {
            cout << fixed << setprecision(1) << dmi << " 2" << endl;
        } else {
            cout << fixed << setprecision(1) << dmi << " 0" << endl;
        }
    }

    return 0;
}



