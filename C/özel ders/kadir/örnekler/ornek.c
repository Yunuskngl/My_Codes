#include <stdio.h>
#include <stdlib.h>

void matrisolusturma(int satir, int sutun, int m[][sutun]){
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun; j++){
            scanf("%d", &m[i][j]);
        }
    }
}

void maxmin(int sutun, int matris[][sutun], int satir){
    int max = matris[0][0];
    int min = matris[0][0];
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun; j++){
            if(max < matris[i][j]){
                max = matris[i][j];
            }
            if(min > matris[i][j]){
                min = matris[i][j];
            }
        }
    }
    printf("max : %d , min : %d \n", max, min);
}

void matrisyazdirma(int sutun, int m[][sutun], int satir){
    for(int i = 0; i < satir; i++){
        for(int h = 0; h < sutun; h++){
            printf("%d ", m[i][h]);
        }
        printf("\n");
    }
}

int main(){
    int satir, sutun;
    printf("Lütfen satır ve sütun değerlerini giriniz: ");
    scanf("%d%d", &satir, &sutun);

    int m[satir][sutun];
    matrisolusturma(satir, sutun, m);
    maxmin(sutun, m, satir);
    matrisyazdirma(sutun, m, satir);

    return 0;
}

