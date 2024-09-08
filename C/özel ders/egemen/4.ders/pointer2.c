#include <stdio.h>
#include <stdlib.h>

int main(){
    int *egemen, *yns , *onur;
    int n=10;
    int p = 20;

    egemen = &n;
    yns =  &p;

    printf("atamadan önce egemen değeri : %d\n", *egemen);
    
    *egemen = *yns +2 ;
    printf("atamadan sonra egemen değeri : %d\n", *egemen);






    return 0; 
}