#include <stdio.h>

typedef struct {
    char isim[50];
    int yas;
    float ortalama;
} Ogrenci;

void ogrenciBilgiYazdir(Ogrenci ogr) {
    printf("İsim: %s\n", ogr.isim);
    printf("Yaş: %d\n", ogr.yas);
    printf("Ortalama: %.2f\n", ogr.ortalama);
}

int main() {
    Ogrenci ogr1 = {"Ahmet", 20, 85.5};
    ogrenciBilgiYazdir(ogr1);

    return 0;
}
