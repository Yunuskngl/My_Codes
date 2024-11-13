#include <stdio.h>

int faktoriyel(int n) {
    if (n == 0)
        return 1; // Temel durum
    else
        return n * faktoriyel(n - 1); // Özyinelemeli durum
}

int main() {
    int sayi = 5;
    printf("%d! = %d\n", sayi, faktoriyel(sayi));
    return 0;
}

