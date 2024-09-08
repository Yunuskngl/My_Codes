#include <stdio.h>
#include <stdlib.h>

int main(){
    float u[5] = {10.2 , 1.2, 3.4 , 6.7 , 5.9 };
    float *ptr;

    ptr = u;

    for(int i = 0 ; i < 5 ; i++){
        printf("%f ", *(ptr+i));
    }
}