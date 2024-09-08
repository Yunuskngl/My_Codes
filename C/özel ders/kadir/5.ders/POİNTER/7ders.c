#include <stdio.h>
#include <stdlib.h>

int main(){
    //int ,char, double,float;

    char karakter = 'c';
    int integerdegerim = 1;
    float floatsayim = 5.43;
    double doublesayim = 2122313123123123123;

    printf("karakterim = %c ,karakterimin adresi = %d\n",karakter , &karakter);
    printf("int degerim = %d , integer adresi = %d \n",integerdegerim,&integerdegerim);
    printf("float degerim = %f , floatim adresi  = %d\n", floatsayim,&floatsayim);
    printf("double degerim = %lf,doublemin adresi = %d\n",doublesayim,&doublesayim);
    return 0;
}