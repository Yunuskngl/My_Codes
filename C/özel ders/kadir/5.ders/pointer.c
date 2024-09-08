#include <stdio.h>
#include <stdlib.h>

int main(){
 /*  1. anlatım tanımlama , değerini değiştirme ve adreslerini yazdırma mantığını anlatma
    int yunus = 10;
    int *p;

    p = &yunus;
    printf("%d\n",*p);
    printf("%d\n",p);
    printf("%d\n",yunus);
    printf("%d\n",&yunus);

    *p = 30;

    printf("%d\n",*p);
    printf("%d\n",p);
    printf("%d\n",yunus);
    printf("%d\n",&yunus);

*/

/**/
    int *ptr1, *ptr2 , *ptr3;
    int n = 10; int n2 = 20;

    ptr1 = &n;
    ptr2 = &n2;

    printf("%d\n",*ptr1);
    printf("%d\n",*ptr2);
    printf("%d\n",ptr1);
    printf("%d\n",ptr2);


    *ptr1 = *ptr2*2;

     printf("%d\n",*ptr1);
    printf("%d\n",*ptr2);
    printf("%d\n",ptr1);
    printf("%d\n",ptr2);

    





}