#include <stdio.h>
#include <stdlib.h>

int main(){
    int t[10]; //array
    int i;
    int *pt;

  
    for(pt = t;pt <t+10 ; pt++){
        *pt = 0;
    }
    printf("\n\n");
    for(pt = t ; pt<t+10;pt++){
        printf("%d\n",*pt);
    }
    
   

    for(i = 0 ; i<10; i++){
        t[i] = 0;

    }
    for(i = 0 ; i< 10 ; i++){
        printf("%d\n",t[i]);
    }
}