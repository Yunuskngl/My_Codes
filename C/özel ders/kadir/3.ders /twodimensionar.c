//2 boyutlu array oluşturup elemanları alma işlemi

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[2][2];

    for(int i=0;i<2;i++)     {
        for(int j=0;j<2;j++)
        {
            printf("Dizinin %d. satir %d. sutun elemanini giriniz: ",i+1,j+1);
            scanf("%d",&dizi[i][j]);
        }
    }

    //matris şeklinde yazdırma
      printf("\n\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",dizi[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}