//tek boyutlu dizide while , for ve do while ile  eleman alma işlemi

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[5];
    int i=0; 
    while(i<5)
    {
        printf("Dizinin %d. elemanini giriniz: ",i+1);
        scanf("%d",&dizi[i]);
        i++;
    }
    printf("\n\n");

    for(i=0;i<5;i++)
    {
        printf("Dizinin %d. elemani: %d\n",i+1,dizi[i]);
    }
    printf("\n\n");
    i=0;
    do
    {
        printf("Dizinin %d. elemanini giriniz: ",i+1);
        scanf("%d",&dizi[i]);
        i++;
    }while(i<5);
    printf("\n\n");
    for(i=0;i<5;i++)
    {
        printf("Dizinin %d. elemani: %d\n",i+1,dizi[i]);
    }
    return 0;
}