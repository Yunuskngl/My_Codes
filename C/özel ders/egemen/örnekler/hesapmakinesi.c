#include <stdio.h>
#include <stdlib.h>

void carpma(int n1,int n2){
    printf("%d\n", n1*n2);
}

void toplama(int n1,int n2){
    printf("%d\n", n1+n2);
}
void cıkarma(int n1,int n2){
    printf("%d\n", n1-n2);
}
void bolme(int n1,int n2){
    printf("%d\n", n1/n2);
}




int main(){
    int num1 , num2;
    printf ("sırasıyla num1 ve num2 değerlerini giriniz.");
    printf("\n");
    scanf("%d%d",&num1,&num2);
    printf("\n");
    int islem;
    

    while (1){
        printf("çarpma için 1 , toplama için 2 , çıkarma 3, bölme 4");
        printf("\n");
        scanf("%d",&islem);


        if(islem == 1){
        carpma(num1,num2);
        }
        else if(islem == 2){
        toplama(num1,num2);
        }
        else if(islem ==3) cıkarma(num1,num2);
        else if (islem == 4) bolme(num1,num2);
        else if (islem == 5){
        break;
        }
        else{
        printf("yanliş değer girildi...");
        }


    }




    return 0;


}