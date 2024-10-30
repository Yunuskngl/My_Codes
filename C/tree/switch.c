#include <stdio.h>
#include <stdlib.h>

int main(){

    double sayi,sayi2;
    int islem;
    printf("lütfen sırasıyla sayi giriniz : ");
    scanf("%lf%lf",&sayi,&sayi2);

    printf("hangi işlemi istiyorsunuz : Çarpma :1 , bölme : 2 , toplama: 3 , çıkarma : 4 ");
    scanf("%d" ,&islem);
    switch (islem)
    {
        case 1 : 
            printf("%.1lf", sayi * sayi2);
            break;
        case 2 : 
            printf("%.3lf", sayi /sayi2);
            break;
        case 3 : 
            printf("%.1lf", sayi + sayi2);
            break;
        case 4 : 
            printf("%.1lf", sayi - sayi2);
            break;
    default:
        printf("program sonlandı...");
        
    }

    return 0;
}

