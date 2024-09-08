#include <stdio.h>
#include <stdlib.h>


int main(){
/*
    int can  = 10; 
    int *p;

    p= &can;

    printf("%d\n",*p);
    printf("%d\n",p);
    printf("%d\n",can);
    printf("%d\n",&can);
    */
    int *sayi;
    int can;
    can = 20;

    sayi = &can;

    printf("%d\n",*sayi);
    printf("%d\n",sayi);
    printf("%d\n",can);
    printf("%d\n",&can);

    can = 30 ; 

    printf("%d\n",*sayi);
    printf("%d\n",sayi);
    printf("%d\n",can);
    printf("%d\n",&can);




    return 0;
}

