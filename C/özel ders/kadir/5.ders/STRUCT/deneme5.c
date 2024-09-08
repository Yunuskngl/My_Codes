#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci_bilgi{
    int numara;
    char ad[10];
    char soyad[10];
    int yas;
};




int main(){
    struct ogrenci_bilgi ogrenci1,ogrenci2;
    ogrenci1.numara=522;
    strcpy(ogrenci1.ad,"can");
    strcpy(ogrenci1.soyad," boz ");
    ogrenci1.yas = 18;

    ogrenci2 = ogrenci1;

    printf("%s\n",ogrenci2.ad);
    printf("%s\n",ogrenci2.soyad);
    printf("%d\n",ogrenci2.numara);
    printf("%d\n",ogrenci2.yas);
    return 0;
}