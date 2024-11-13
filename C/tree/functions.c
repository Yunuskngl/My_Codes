#include <stdio.h>
#include <stdlib.h>

void merhaba();
void sayigoster();
int sayidegistir(int sayi1);



int main(){
    merhaba();
    int sayi1;
    scanf("%d",&sayi1);
    sayigoster(sayi1);
    float num2 = sayidegistir(sayi1);
    sayigoster(num2);


}

void merhaba(){
    printf("merhaba\n");
    printf("sayı giriniz : ");
}
void sayigoster(int sayi1){
    printf("%d\n",sayi1);
}

int sayidegistir(int sayi1){
    sayi1/=4;
    return sayi1;
}