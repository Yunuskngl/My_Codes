#include <stdio.h>
#include <stdlib.h>


int faktoryel(int num){
    int sum =1 ;
    for(int i=num;i>0;i--){
        sum *= i;
    }
    return sum;
}

int main(){
    for(int i = 0 ; i<10 ; i++){
        printf("%d\n",faktoryel(i));
    }

}