#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dosya;
    char kelime[50][20]; // 50 kelime, her kelime 20 karakterden oluşuyor
    int i = 0;

    // Dosyayı aç
    if ((dosya = fopen("kdizim.txt", "r")) != NULL) {
        // Dosya sonuna kadar döngüyü devam ettir
        while (fscanf(dosya, "%s", kelime[i]) != EOF && i < 50) {
            printf("%s ", kelime[i]);
            i++;
        }
        printf("\n");
    } else {
        printf("Dosya bulunamadı.\n");
    }

    // Dosyayı kapat
    fclose(dosya);

    return 0;
}
