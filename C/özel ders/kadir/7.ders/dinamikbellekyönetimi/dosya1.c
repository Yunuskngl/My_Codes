#include <stdio.h>
#include <stdlib.h>

int main() {
    int *kadir;
    int n;

    n = 10;
    int i;
    printf("Girdiğimiz sayı değeri: %d\n", n);

    // Bellek tahsis et
    kadir = (int*) malloc(n * sizeof(int));

    // Diziyi doldur
    for (i = 0; i < n; i++) {
        kadir[i] = i + 1;
    }

    // Değerleri yazdır
    printf("Değerler:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", kadir[j]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(kadir);

    // Belleği serbest bıraktıktan sonra diziye erişmeyi denemeyin.

    return 0;
}
