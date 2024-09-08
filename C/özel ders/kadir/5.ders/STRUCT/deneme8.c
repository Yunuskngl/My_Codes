#include <stdio.h>
#include <stdlib.h>

typedef enum renkler{
    ocak = 10,
    subat,
    mart,
    nisan,
    mayis,
    haziran,
    temmuz,
    agustos,
    eylul,
    ekim,
    kasim,
    aralik
}aylar;

void ayi_goster(aylar can){
    switch(can){
    case ocak:
        printf("ocak");
        break;
    case subat:
        printf("subat");
        break;
    case mart:
        printf("mart");
        break;
    case nisan:
        printf("nisan");
        break;
    default:
        printf("böyle bir ay yok");
        break;
    }
}


int main(){
    aylar can = 11;
    ayi_goster(can);
    return 0;
}