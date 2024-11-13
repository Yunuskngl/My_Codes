#include <stdio.h>

struct Ogrenci {
    char isim[50];
    int yas;
    float ortalama;
};

int main() {
    struct Ogrenci ogr1;

    // Kullanıcıdan bilgi alma
    printf("Öğrenci ismini girin: ");
    scanf("%s", ogr1.isim);
    printf("Öğrenci yaşını girin: ");
    scanf("%d", &ogr1.yas);
    printf("Öğrenci ortalamasını girin: ");
    scanf("%f", &ogr1.ortalama);

    // Bilgileri yazdırma
    printf("\nÖğrenci Bilgileri:\n");
    printf("İsim: %s\n", ogr1.isim);
    printf("Yaş: %d\n", ogr1.yas);
    printf("Ortalama: %.2f\n", ogr1.ortalama);

    return 0;
}
