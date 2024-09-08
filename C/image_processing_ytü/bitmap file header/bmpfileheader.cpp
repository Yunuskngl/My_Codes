#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)


struct BMPfileHeader{
    char bftype1;
    char bftype2;
    int bfsize;
    short int bfreserved1;
    short int bfreserved2;
    int bfoffBits;

};

void printBMPFileHeader(struct BMPfileHeader bmpfh){
    printf("The Information of Bitmap : \n");
    printf("bftype1 : %c \n",bmpfh.bftype1);
    printf("bftype2 : %c \n",bmpfh.bftype2);
    printf("bfreserved1 : %d \n",bmpfh.bfreserved1);
    printf("bfreserved2: %d \n",bmpfh.bfreserved2);
    printf("BfOffBits : %d \n",bmpfh.bfoffBits);

}

int main(){
    FILE *fp;
    struct BMPfileHeader bmpfh;
    fp = fopen("kelebek.bmp" , "rb");
    if(fp== NULL){
        printf("Fıle is not opened");
        exit(1);

    }
    fread(&bmpfh,sizeof(struct BMPfileHeader),1,fp);
    printBMPFileHeader(bmpfh);
    fclose(fp);
    return 0; 

}
