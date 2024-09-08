#include <stdio.h>
#include <stdlib.h>

int main() {
    int *yns;
    int a;

    // Kullanıcıdan sayıyı al
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &a);

    // Bellek tahsis et
    yns = (int*) calloc(a, sizeof(int));

    // Bellek tahsisi başarısız ise
    if (yns == NULL) {
        printf("Bellek tahsisi başarısız.\n");
        return 1; // Programı sonlandır
    }

    // Elemanları doldur
    for (int i = 0; i < a; i++) {
        yns[i] = i + 1;
    }

    // Elemanları ekrana yazdır
    printf("Elemanlar:\n");
    for (int j = 0; j < a; j++) {
        printf("%d, ", yns[j]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(yns);

    return 0;
}
