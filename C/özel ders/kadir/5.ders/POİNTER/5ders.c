#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {10,20,30,40,50};
    int *ptr;

    ptr = arr;
    ptr++;
    
    printf("%d",ptr);
    return 0  ;
}