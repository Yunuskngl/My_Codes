#include <stdio.h>
#include <stdlib.h>

//palendrom  = aba  aba
int main(){
    char cumlem[100];
    char *p1,*p2;
    int kontrol ; 

    printf ("lütfen 100 karaktere kadar cümlenizi giriniz.\n");
    gets(cumlem);

    for(p2 = cumlem; *p2; p2++);

    //"abc\0"
    p2--;
    kontrol  = 1; 
    for(p1 = cumlem; kontrol && p1<p2 ; p1++,p2--){
        if(*p1 != *p2){
            kontrol = 0;
        }
    }
    if (kontrol == 1){
        printf("girilen %s bir palendromdur.",cumlem);
    }
    else{
        printf("girilen %s bir palendrom degildir",cumlem);
    }
    return 0 ; 

    
}