#include <stdio.h>
#include <stdlib.h>


struct ogrenci{
    char ad[10];
    char soyad[10];
    int yas;
};

int main(){
    struct ogrenci can = {"can","kngl",27};

    printf("%s \t %s \t %d",can.ad,can.soyad,can.yas);
}