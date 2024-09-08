#include <stdio.h>
#include <stdlib.h>

int main(){
    char can[100] = "canan";
    char *p1;

    p1 = can;

    printf(" %c ", *(p1+10));



    return 0;
}