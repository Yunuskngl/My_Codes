#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *abc;
    char sentence[50];
    int n, i;

    // Dosyayı yazma modunda aç
    abc = fopen("bilgi.txt", "w");

    // Dosya açma başarısız ise
    if (abc == NULL) {
        printf("Dosya bulunamadı.\n");
    } else {
        // Kullanıcıdan bir cümle al
        printf("Lütfen bir cümle girin: \n");
        fgets(sentence, sizeof(sentence), stdin);

        // Kullanıcıdan kaç satır yazmak istediğini al
        printf("Kaç satır yazı istersiniz: ");
        scanf("%d", &n);

        // Belirtilen sayıda satırda cümleyi dosyaya yaz
        for (i = 1; i <= n; i++) {
            fprintf(abc, "%d : Cümle: %s\n", i, sentence);
        }

        // Dosyayı kapat
        fclose(abc);
        printf("Başarıyla tamamlandı.\n");
    }

    return 0;
}
