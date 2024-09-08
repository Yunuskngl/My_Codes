/*
bir çiftlikte tavşanların sayısı 1042 iken , kuşların sayısı 2272 dir . 
bir yılda tavşanlar %3.8 oranında çoğalırkne ,kuşlar %1.2 oranında çoğalıyor.
tavşanların kuşların sayısını kaç yıl sonra geçeceğini bulunuz.



*/

#include <stdio.h>

int main(){
    int tavsanlar = 1042;
    int kuslar = 2272;
    int yil = 0;

    while(tavsanlar <=kuslar){
        tavsanlar += tavsanlar * 0.038;
        kuslar += kuslar * 0.012;
        yil++;
    }
    printf("yıl : %d\n",yil);
    printf("%d\n",tavsanlar);
    printf("%d",kuslar);
}







