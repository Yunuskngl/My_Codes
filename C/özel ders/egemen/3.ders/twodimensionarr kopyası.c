//2 boyutlu array oluşturup elemanları alma işlemi

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[2][2] = {(4,5),(6,7)};
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Dizinin %d. satir %d. sutun elemanini giriniz: ",i+1,j+1);
            scanf("%d",&dizi[i][j]);
        }
    }

    //matris şeklinde yazdırma
      printf("\n\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }


    printf("\n\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Dizinin %d. satir %d. sutun elemani: %d\n",i+1,j+1,dizi[i][j]);
        }
    }
    return 0;
}