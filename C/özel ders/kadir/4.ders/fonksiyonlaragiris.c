/*#include <stdio.h>
#include <stdlib.h>



void ynsfunc(int yns){
    
    if(yns % 2 == 0){
        printf("Cift sayi\n");
    }else{
        printf("Tek sayi\n");
    }
   
}


int main(){
    int num ; 
    printf("Enter a number: ");
    scanf("%d", &num);
 
    ynsfunc(num);
    return 0;
}

*/


#include <stdio.h>
#include <stdlib.h>

void tekmiciftmi( int num){
    if(num % 2 == 0 ){
        printf("girdiginiz sayi çift sayidir.");
    }
    else{
        printf("girdiginiz sayi tek sayidir.");
    }

}

int main(){
    int egemen; 
    printf("lütfen deger girebilir misiniz : ");
    scanf("%d",&egemen);

    tekmiciftmi(egemen);


    return 0;


}