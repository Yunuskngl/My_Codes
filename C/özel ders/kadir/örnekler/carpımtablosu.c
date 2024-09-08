#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("-----------------------------------");
    printf("\n");
    for(int i = 1 ; i<=10 ; i++){
        for(int j = 1 ; j<=10 ; j++){
            printf("  %d ", i*j);
        }
        printf("\n");

    }
    return 0 ; 
}