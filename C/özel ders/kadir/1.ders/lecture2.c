#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    int num1 = 5;
    float num2 = 3.5; 
    double num3 = 7.3;  
    char ch = 'A';

    int sum  = 10;
/*
    //switch case yapısı 
    switch (ch) {
        case 'A':
            printf("A harfi girildi.\n");
            
        case 'B':
            printf("B harfi girildi.\n");
            
        case 'C':
            printf("C harfi girildi.\n");
            
        default:
            printf("A, B ve C harflerinden farklı bir harf girildi.\n");
    }*/

    //break yapısı 
/*
    for (int i = 1; i <= 10; i++) {

        
        printf("%d\n", i);
        if (i ==5) {break;}
    }
  */ 
    //continue yapısı
    for(int i = 1; i <= 10; i++) {
        if (i == 5) {continue;}
        printf("%d\n", i);
    }

    //boolen data type yapısı
    bool x=true;

    printf("%d",x);
    return 0;
}