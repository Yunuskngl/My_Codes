#include <stdio.h>

typedef union {
    int id;
    float ortalama;
    char harfNotu;
}Veri;

int main() {
    Veri ogrenciVerisi;

    // ID bilgisi atama ve yazdırma
    ogrenciVerisi.id = 12345;
    printf("ID: %d\n", ogrenciVerisi.id);

    // Ortalamayı atama ve yazdırma
    ogrenciVerisi.ortalama = 87.5;
    printf("Ortalama: %.2f\n", ogrenciVerisi.ortalama);

    // Harf notu atama ve yazdırma
    ogrenciVerisi.harfNotu = 'A';
    printf("Harf Notu: %c\n", ogrenciVerisi.harfNotu);

    // Tekrar yazdırma - Önceki veriler üzerine yazıldığını göreceksiniz
    printf("\nYeniden Yazdırma:\n");
    printf("ID: %d\n", ogrenciVerisi.id);           // Anlamlı olmayabilir
    printf("Ortalama: %.2f\n", ogrenciVerisi.ortalama); // Anlamlı olmayabilir
    printf("Harf Notu: %c\n", ogrenciVerisi.harfNotu);  // 'A' olarak kalır

    return 0;
}
