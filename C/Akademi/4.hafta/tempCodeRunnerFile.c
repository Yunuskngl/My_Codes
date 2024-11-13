 #include <stdio.h>
#include <locale.h>

// Struct tanımlaması
struct OgrenciStruct {
    int id;
    float notOrtalamasi;
    char harfNotu;
};

// Union tanımlaması
union OgrenciUnion {
    int id;
    float notOrtalamasi;
    char harfNotu;
};

int main() {
    setlocale(LC_ALL, "");

    // Struct ve Union örneklerine varsayılan değerler atama
    struct OgrenciStruct ogrenciStruct = {123, 85.5, 'A'};
    union OgrenciUnion ogrenciUnion = {123}; // İlk değer id olarak atanır, diğerleri geçersiz olur

    // Struct ve Union değerlerini yazdırma
    printf("Struct Verileri:\nID: %d\nNot Ortalaması: %.2f\nHarf Notu: %c\n", 
           ogrenciStruct.id, ogrenciStruct.notOrtalamasi, ogrenciStruct.harfNotu);

    printf("\nUnion Verileri:\nID: %d\nNot Ortalaması: %.2f\nHarf Notu: %c\n", 
           ogrenciUnion.id, ogrenciUnion.notOrtalamasi, ogrenciUnion.harfNotu);

    // Bellek boyutlarını yazdırma
    printf("\nStruct Boyutu: %lu bayt\nUnion Boyutu: %lu bayt\n", 
           sizeof(ogrenciStruct), sizeof(ogrenciUnion));

    return 0;
}
