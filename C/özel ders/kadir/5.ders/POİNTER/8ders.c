#include <stdio.h>
#include <stdlib.h>

void toplama(int *num1, int *num2) {
    printf("%d\n", (*num1 + *num2));
}

void cikarma(int *num1, int *num2) {
    printf("%d\n", (*num1 - *num2));
}

void bolme(int *num1, int *num2) {
    if (*num2 != 0) {
        printf("%d\n", (*num1 / *num2));
    } else {
        printf("Sifira bolme hatasi!\n");
    }
}

void carpma(int *num1, int *num2) {
    printf("%d\n", (*num1 * *num2));
}

int main() {
    int a, b, islem;

    printf("Lutfen bir deger giriniz: ");
    scanf("%d %d", &a, &b);

    while (1) {
        printf("Lutfen istediginiz islemi secin (1-4) veya cikmak icin (9): ");
        scanf("%d", &islem);

        if (islem == 1) {
            toplama(&a, &b);
        } else if (islem == 2) {
            cikarma(&a, &b);
        } else if (islem == 3) {
            bolme(&a, &b);
        } else if (islem == 4) {
            carpma(&a, &b);
        } else if (islem == 9) {
            printf("Program sonlandirildi.\n");
            break;
        } else {
            printf("Gecersiz deger! Lutfen 1 ve 4 arasinda bir deger giriniz.\n");
        }
    }

    return 0;
}
