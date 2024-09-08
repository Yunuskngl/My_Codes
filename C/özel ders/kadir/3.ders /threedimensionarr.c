//3 boyutlu array 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi2[2][2][2] = {{{1,2},{3,4}},{{5,6},{7,8}}};
    int dizi[2][2][2];
    int i,j,k;
    for(i=0;i<2;i++)  //0 olarak başladı 
    {
        for(j=0;j<2;j++)  // 0 olarak başladı
        {
            for(k=0;k<2;k++) // i= 0 , j= 0 , 
            {
                printf("Dizinin %d. satir %d. sutun %d. derinlik elemanini giriniz: ",i+1,j+1,k+1);
                scanf("%d",&dizi[i][j][k]);
            }
        }
    }
    printf("\n\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                printf("Dizinin %d. satir %d. sutun %d. derinlik elemani: %d\n",i+1,j+1,k+1,dizi[i][j][k]);
            }
        }
    }
    return 0;
}

