#include <stdio.h>
#include <stdlib.h>

int main(){
    int t[10];  //array=dizi  
    int *pt;

    for(pt = t ; pt < t+10;pt++){
        scanf("%d",pt);

    }

    for(pt = t ; pt < t+10;pt++){
        printf("%d ", *pt);


    }
    
    
    
}