#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#pragma pack(1)


void negativeImage(Image *image){
    DWORD w,h,rowsize,i,j;
    w = image->bmpih.biw;
    h=image->bmpih.bih;
    rowsize = (image->bmpih.bibitcount*w+31)/32*4;
    for(i = 0 ; i<rowsize*h; i++){
        image->data[i] = 256 - image->data[i];
    }
    for(i = 0 ; i<rowsize*h; i++){
        image->data[i] = pow(2,image->bmpih.bibitcount)-1-image->data[i];
    }


}


void F(Image *image){
    int i,j,h,w,rowsize;
    h = image->bmpih.bih;
    w = image->bmpih.biw;
    rowsize = (w*image->bmpih.bibitcount +31)/32*4;
    int sum = 0 ; 
    for(i = 0 ; i<rowsize*h ;i++){
        sum += image->data[i];

    }
    t = sum /h*rowsize;

    for(i = 0 ; i<h ; i++){
        for(j = 0 ; j<rowsize ; j++){
            if(image->data[i*rowsize +j] <= t)
        }
    }
}








