#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dosya;
    char satir[100];

    // Dosyayı okuma modunda aç
    dosya = fopen("bilgi.txt", "r");

    // Dosya açma başarısız ise
    if (dosya == NULL) {
        printf("Dosya açılmadı.\n");
    } else {
        // Dosyadan satır satır oku ve ekrana yaz
        while (fgets(satir, sizeof(satir), dosya) != NULL) {
            printf("%s", satir);
        }
        
        // Dosyayı kapat
        fclose(dosya);
        printf("Dosya okuma başarılı.\n");
    }

    return 0;
}
