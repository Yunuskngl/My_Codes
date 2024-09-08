#include <stdio.h>
#include <stdlib.h>
#define pi 3.14



float  daire (int r){
    float alan ;
    alan  = pi * r * r;
    return alan; 
}

int main(){
    int num; 
    printf("lütfen bana bir sayı değeri girin : \n");
    scanf("%d",&num);

    float sonuc ; 
    sonuc = daire(num);
    printf("%f",sonuc);
    return 0;
}