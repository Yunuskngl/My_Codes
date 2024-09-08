#include <stdio.h>
#include <stdlib.h>

void degistir(int *ad1, int *ad2){
    int temp ;
    temp = *ad1;
    *ad1 = *ad2;
    *ad2 = temp;
}


int main(){
    int a = 10, b= 20;
    printf("cağirmadan önce %d %d \n",a,b);
    degistir(&a,&b);
    printf("cağirdıktan sonra %d %d \n",a,b);
    return 0; 
}