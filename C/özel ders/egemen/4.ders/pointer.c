#include <stdio.h>
#include <stdlib.h>

int main(){
    int sayi =10;



    int *a;  //pointer,  belleğe erişimimiz kolay. bellek ile alakalı işlemler yaparken
                // bize çok kolaylık sağlıyor.

    a =  &sayi ;   

    printf("%d\n",*a);
    printf("%d\n",a);
    printf("%d\n",sayi);
    printf("%d",&sayi);

    int *ptr ; 
    int b;  
    b = 20;


    printf("%d\n",b);
    printf("%d\n",&b);




    ptr = &b;   //1805136268

    *ptr =30;

    printf("%d\n",*ptr);
    printf("%d\n",ptr);
    printf("%d\n",b);
    printf("%d",&b);

    return 0;
}