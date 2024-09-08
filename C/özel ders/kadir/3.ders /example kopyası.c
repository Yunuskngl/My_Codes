//2 boyutlu array oluşturup toplama işlemi ; 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[2][2];
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("Dizinin %d. satir %d. sutun elemanini giriniz: ",i+1,j+1);
            scanf("%d",&dizi[i][j]);
        }
    }


    printf("\n\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("Dizinin %d. satir %d. sutun elemani: %d\n",i+1,j+1,dizi[i][j]);
        }
    }
    int toplam=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            toplam  = toplam + dizi[i][j];
            //toplam += dizi[i][j];
        }
    }
printf("Dizinin elemanlarinin toplami: %d",toplam);
    return 0;
}   

