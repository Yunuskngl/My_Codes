#include <stdio.h>
#include <stdlib.h>

int main() {
    int *point;
    int sayi;

    // Kullanıcıdan sayıyı al
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &sayi);

    // Bellek tahsis et
    point = (int*) calloc(sayi, sizeof(int));

    // Bellek tahsisi başarısız ise
    if (point == NULL) {
        printf("Bellek tahsisi başarısız.\n");
        return 1; // Programı sonlandır
    }

    // Kullanıcıdan elemanları al
    printf("Elemanları girin:\n");
    for (int i = 0; i < sayi; i++) {
        scanf("%d", point + i);
    }

    // Elemanları ekrana yazdır
    printf("Elemanlar:\n");
    for (int j = 0; j < sayi; j++) {
        printf("%d ", point[j]);
    }
    printf("\n");

    // Bellek boyutunu artır
    int yeni_sayi;
    printf("\nBellek boyutunu artırmak için yeni boyutu girin: ");
    scanf("%d", &yeni_sayi);

    // Bellek boyutunu artır
    int *gecici = realloc(point, yeni_sayi * sizeof(int));
    if (gecici == NULL) {
        printf("Bellek boyutunu artırma başarısız.\n");
        free(point); // Önceki bellek bloğunu serbest bırak
        return 1; // Programı sonlandır
    } else {
        point = gecici; // Yeni bellek bloğunu göster
    }

    // Yeni elemanları ekle
    printf("Yeni elemanları girin:\n");
    for (int k = sayi; k < yeni_sayi; k++) {
        scanf("%d", point + k);
    }

    // Tüm elemanları ekrana yazdır
    printf("Tüm elemanlar:\n");
    for (int m = 0; m < yeni_sayi; m++) {
        printf("%d ", point[m]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(point);

    return 0;
}
