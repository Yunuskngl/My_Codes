#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dosya;
    dosya = fopen("ogrenci.txt", "a"); // 'a' modu ile dosyayı eklemeli modda aç

    char isim[50], okul[50], bolum[50];

    // Kullanıcıdan öğrenci bilgilerini al
    printf("Adınız: ");
    fgets(isim, sizeof(isim), stdin);
    printf("Okul: ");
    fgets(okul, sizeof(okul), stdin);
    printf("Bölümünüz: ");
    fgets(bolum, sizeof(bolum), stdin);

    // Dosyaya öğrenci bilgilerini yaz
    fprintf(dosya, "Ad: %sOkul: %sBölüm: %s\n", isim, okul, bolum);

    // Dosyayı kapat
    fclose(dosya);

    return 0;
}
