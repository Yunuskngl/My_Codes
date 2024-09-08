#include <stdio.h>
#include <stdlib.h>

int main(){
    int yns[100],kadir[100];
    int *sayi1,*sayi2;
    int n,m;
    int i;
    printf("ilk dizimizin elemanlan sayisi(max 50) : \n");
    scanf("%d",&n);
    for(sayi1 = yns;sayi1 <= yns+n -1 ; sayi1++){
        printf("eleman %d : ",sayi1-yns);
        scanf("%d",sayi1);
    }
    printf("ikinci dizimin eleman sayisi : \n");
    scanf("%d",&m);
    for(sayi2 = kadir ; sayi2 < kadir + m  ; sayi2++){
        printf("eleman %d : ",sayi2 -kadir);
        scanf("%d",sayi2);
    }

    printf("ilk dizimiz : \n");
    for(i = 0 ; i <n ;i++){
        printf("%4d",*(yns+i));
    }
    printf("ikinci dizimiz : \n");
    for(i = 0 ; i <n ;i++){
        printf("%4d",*(kadir+i));
    }


    for(sayi1 = yns + n ,sayi2 = kadir + m;sayi2 < kadir + m ; sayi1++ , sayi2++ ){
        *sayi1 = *sayi2;
    }

    printf("\n");

    printf("birlestirmeden sonra  : \n");
    for(i = 0; i< n+m ; i++){
        printf("%4d", *(yns+i));
    }

    return 0;








}



