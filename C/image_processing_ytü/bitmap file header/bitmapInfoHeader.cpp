#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct BitmapInfoHeader{
    int biSize;
    int biWidth;
    int biHeight;
    short int biPlanes;
    short int biBitCount;
    int biSizeImage;
    int biCompression;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
};
void printBitmapInfoHeader(struct BitmapInfoHeader bmpfh){
    printf("The Information of Bitmap Info Header : \n");
    printf("biSize : %d \n",bmpfh.biSize);
    printf("biWidth : %d \n",bmpfh.biWidth);
    printf("biHeight : %d \n",bmpfh.biHeight);
    printf("biPlanes: %d \n",bmpfh.biPlanes);
    printf("biBitCount : %d \n",bmpfh.biBitCount);
    printf("biSizeImage : %d \n",bmpfh.biSizeImage);
    printf("biCompression : %d \n",bmpfh.biCompression);
    printf("biXPelsPerMeter : %d \n",bmpfh.biXPelsPerMeter);
    printf("biYPelsPerMeter: %d \n",bmpfh.biYPelsPerMeter);
    printf("biClrUsed : %d \n",bmpfh.biClrUsed);
    printf("biClrImportant : %d \n",bmpfh.biClrImportant);
}

int main(){
    FILE *fp;
    struct BitmapInfoHeader bmpfh;
    fp = fopen("kelebek.bmp" , "rb");
    if(fp== NULL){
        printf("Fıle is not opened");
        exit(1);

    }
    fread(&bmpfh,sizeof(struct BitmapInfoHeader),1,fp);
    printBitmapInfoHeader(bmpfh);
    fclose(fp);
    return 0; 

}