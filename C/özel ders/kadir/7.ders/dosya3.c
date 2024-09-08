#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dosya;
    char **sayılar; // Öğrenci numaralarını tutacak dinamik dizi
    char **adlar;   // Öğrenci adlarını tutacak dinamik dizi
    int *notlar;    // Öğrenci notlarını tutacak dinamik dizi
    int kapasite = 10; // Başlangıç kapasitesi
    int i = 0;

    // Bellek tahsisi
    sayılar = (char**)malloc(kapasite * sizeof(char*));
    adlar = (char**)malloc(kapasite * sizeof(char*));
    notlar = (int*)malloc(kapasite * sizeof(int));

    // Dosyayı aç
    if ((dosya = fopen("ogrenci.txt", "r")) != NULL) {
        // Dosya sonuna kadar döngüyü devam ettir
        while (fscanf(dosya, "%s %s %d", sayılar[i], adlar[i], &notlar[i]) != EOF) {
            printf("%s %s %d\n", sayılar[i], adlar[i], notlar[i]);
            i++;
            // Dizilerin boyutunu kontrol et ve gerekirse yeniden boyutlandır
            if (i >= kapasite) {
                kapasite *= 2;
                sayılar = (char**)realloc(sayılar, kapasite * sizeof(char*));
                adlar = (char**)realloc(adlar, kapasite * sizeof(char*));
                notlar = (int*)realloc(notlar, kapasite * sizeof(int));
            }
        }
    } else {
        printf("Dosya bulunamadı.\n");
    }

    // Belleği serbest bırak
    fclose(dosya);
    free(sayılar);
    free(adlar);
    free(notlar);

    return 0;
}
