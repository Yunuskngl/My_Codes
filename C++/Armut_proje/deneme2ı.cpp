#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Fonksiyon prototipleri
vector<double> ısıTransferiSimülasyonu(double alpha, double delta_t, double delta_x, int adım_sayısı);

int main() {
    // Parametrelerin tanımlanması
    double delta_t = 0.01; // Zaman adımı
    double delta_x = 0.1;  // Uzay adımı
    int adım_sayısı = 100; // Toplam adım sayısı

    // Isı yayma katsayısının hesaplanması
    double k = 400;        // Isı yayma katsayısı (W/mK) - Bakır için varsayılan değer
    double p = 8960;       // Yoğunluk (kg/m^3) - Bakır için varsayılan değer
    double c_p = 0.385;    // Spesifik ısı kapasitesi (J/kgK) - Bakır için varsayılan değer
    double alpha = k / (p * c_p); // Isı yayma katsayısı

    // Isı transferi simülasyonunun çağrılması
    vector<double> sonuçlar = ısıTransferiSimülasyonu(alpha, delta_t, delta_x, adım_sayısı);

    // Hata hesabı
    double hata = 0.0;
    double tolerans = 1e-3; // Kabul edilebilir hata toleransı

    // Hata hesaplaması
    for (int i = 1; i < sonuçlar.size(); ++i) {
        hata += pow(sonuçlar[i] - sonuçlar[i - 1], 2); // Hata kareleri toplamı hesaplanır
    }
    hata = sqrt(hata); // Toplam karelerin karekökü alınır

    // Hatanın toleransın altında olup olmadığı kontrol edilir
    if (hata <= tolerans) {
        cout << "Hata toleransı sağlandı: " << hata << " <= " << tolerans << endl;
    } else {
        cout << "Hata toleransı sağlanamadı: " << hata << " > " << tolerans << endl;
    }

    // Tüm sonuçların yazdırılması
    cout << "Tüm sonuçlar:" << endl;
    for (int i = 0; i < sonuçlar.size(); ++i) {
        cout << "Adım " << i << ": " << sonuçlar[i] << endl;
    }

    return 0;
}

// Isı transferi simülasyonu fonksiyonu
vector<double> ısıTransferiSimülasyonu(double alpha, double delta_t, double delta_x, int adım_sayısı) {
    // Isı transferi sonuçlarının tutulacağı vektör
    vector<double> sıcaklık(adım_sayısı + 1, 0.0);

    // Başlangıç koşulu (dış yüzey 100 C, iç yüzey 0 C)
    sıcaklık[0] = 100.0;
    sıcaklık[sıcaklık.size() - 1] = 0.0;

    // Geçici sıcaklık vektörü
    vector<double> temp(adım_sayısı + 1, 0.0);

    // Isı transferi denkleminin her adımda uygulanması
    for (int n = 0; n < adım_sayısı; ++n) {
        // Geçici sıcaklık vektörünü güncelle
        for (int i = 1; i < sıcaklık.size() - 1; ++i) {
            temp[i] = (1 - (2 * alpha * delta_t) / (delta_x * delta_x)) * sıcaklık[i] +
                      (alpha * delta_t) / (delta_x * delta_x) * (sıcaklık[i + 1] - sıcaklık[i - 1]);
        }
        // Sonuçları güncelle
        for (int i = 1; i < sıcaklık.size() - 1; ++i) {
            sıcaklık[i] = temp[i];
        }
    }

    return sıcaklık;
}
