#include <stdio.h>
#include <stdlib.h>

void carpma(int n1,int n2){
    printf("%d\n",n1*n2);
}
void bolme(int n1,int n2){
    printf("%d\n",n1/n2);
}
void cıkarma(int n1,int n2){
    printf("%d\n",n1-n2);
}
void toplama(int n1,int n2){
    printf("%d\n",n1+n2);
}



int main(){ 
    int num1,num2;
    printf("lütfen sırasıyla değer giriniz...");
    scanf("%d%d",&num1,&num2);


    int islem ;
    while (1){
        printf("çarpma : 1 , bölme : 2 , çıkarma : 3 , toplama : 4 , programı durdurmak için : 5");
        scanf("%d",&islem);

        if(islem == 1 ){
            carpma(num1,num2);
        }
        else if (islem == 2){
            bolme(num1,num2);
        }
        else if (islem == 3) cıkarma(num1,num2);
        else if (islem == 4) toplama(num1,num2);
        else if (islem == 5) break;
        else {
            printf("girilen değer geçersiz.");
        }

    }
    printf("program durdururldu...");
    
    


}