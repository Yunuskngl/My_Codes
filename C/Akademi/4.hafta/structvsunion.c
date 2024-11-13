#include <stdio.h>
#include <locale.h>

// Struct definition
struct OgrenciStruct {
    int id;
    float notOrtalamasi;
    char harfNotu;
    double budget;
};

// Union definition
union OgrenciUnion {
    int id;
    float notOrtalamasi;
    char harfNotu;
    double budget;
};

int main() {
    setlocale(LC_ALL, "");

    // Struct and union instances
    struct OgrenciStruct ogrenciStruct = {123, 90.8, 'A', 10.4};
    union OgrenciUnion ogrenciUnion;
    
    // Assigning values to union (only the last assigned field will be valid)
    ogrenciUnion.id = 123;
    ogrenciUnion.notOrtalamasi = 90.8;
    ogrenciUnion.harfNotu = 'A';
    ogrenciUnion.budget = 10.4;


    // Printing memory sizes
    printf("\nStruct Boyutu: %zu bayt\nUnion Boyutu: %zu bayt\n", 
           sizeof(ogrenciStruct), sizeof(ogrenciUnion));

    return 0;
}

