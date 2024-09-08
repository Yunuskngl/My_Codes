/*#include <stdio.h>
#include <stdlib.h>

int kare_alma(int num){  
    printf("Kare alma fonksiyonu\n");
    printf("%d\n", num*num);
    return num * num;    
}

int main(){
    int num ; 
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Karesi: %d\n", kare_alma(num));
    return 0;
}*/









#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int kare_alma(int yns){
    yns = pow(yns,3);


    
    
    return yns;
    printf("değer gönderiliyor...");
}

void tekmiciftmi( int num){
    if(num % 2 == 0 ){
        printf("girdiginiz sayi çift sayidir.");
    }
    else{
        printf("girdiginiz sayi tek sayidir.");
    }

}

int main(){
    int num;
    printf("deger giriniz ? ");
    scanf("%d",&num);

    //int sonuc = kare_alma(num);

    printf("%d",kare_alma(num));
    return 0;
 
}














