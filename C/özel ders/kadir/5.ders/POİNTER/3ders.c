#include <stdio.h>
#include <stdlib.h>


void degistir(int *ad1 , int *ad2){
    int temp;
    temp = *ad1;  
    *ad1 = *ad2;
    *ad2 = temp;
}

int main(){
    int a = 10 , b = 20;
    printf("cağırmadan önce %d %d\n",a,b);
    degistir(&a,&b);
    printf("değişmeden sonra %d %d ", a,b);

    return 0 ; 

}