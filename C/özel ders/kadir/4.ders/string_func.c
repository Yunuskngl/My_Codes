#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() {

    //strlen() fonksiyonu
    char isim[] = "Merhabalar dünya"; 
    printf("%d\n", strlen(isim));  //string length 

    
    //strcmp() fonksiyonu
    char isim1[] = "mercedes";
    char isim2[] = "bmw";
    printf("%d\n", strcmp(isim1, isim2)); //strcmp fonksiyonu karakter dizilerini karşılaştırır ve farklı olan karakterlerin ascii değerlerinin farkını döndürür

    //strncmp() fonksiyonu
    char isim3[] = "mercedes";
    char isim4[] = "audi";
    printf("%d\n", strncmp(isim3, isim4, 3)); //strncmp fonksiyonu karakter dizilerini karşılaştırır ve belirtilen sayıda karakteri karşılaştırır ve bize farklı olan karakterlerin ascii değerlerinin farkını döndürür


    //strcpy() fonksiyonu
    char isim5[] = "mercedes";
    char isim6[20];
    strcpy(isim6, isim5); //strcpy fonksiyonu karakter dizilerini kopyalar
    printf("%s\n", isim6); //isim6 dizisini ekrana yazdırdık



    //strncpy() fonksiyonu
    char isim7[] = "mercedes";  
    char isim8[20];
    printf("%s\n", strncpy(isim8, isim7, 3)); //strncpy fonksiyonu karakter dizilerini kopyalar ve belirtilen sayıda karakteri kopyalar

    //strcat() fonksiyonu
    char isim9[] = "mercedes";
    char isim10[] = "bmw";
    strcat(isim9, isim10); //strcat fonksiyonu karakter dizilerini birleştirir
    printf("%s\n", isim9); //isim9 dizisini ekrana yazdırdık

    //strncat() fonksiyonu
    char isim11[] = "mercedes";
    char isim12[] = " bmw";
    strncat(isim11, isim12, 3); //strncat fonksiyonu karakter dizilerini birleştirir ve belirtilen sayıda karakteri birleştirir
    printf("%s\n", isim11); //isim11 dizisini ekrana yazdırdık

    //strstr() fonksiyonu
    char isim13[] = "mercedes";
    char isim14[] = "mer";
    printf("%s\n", strstr(isim13, isim14)); //strstr fonksiyonu karakter dizilerini karşılaştırır ve belirtilen karakter dizisini arar ve bulursa bulunduğu yeri döndürür


    //--------------------------------------------------------------------------------

    //gets ile fgets string ifadeyi almak arasındaki farklar

    //gets fonksiyonu
    char isim15[20];
    printf("isminizi giriniz: ");
    //gets(isim15); //kullanıcıdan isim alıyoruz

    for(int i = 0 ; i< 20 ; i++){
        scanf("%c",isim15[i]);
    }
    //fgets fonksiyonu
    char isim16[20];
    printf("isminizi giriniz: ");
    fgets(isim16, 4, stdin); //kullanıcıdan isim alıyoruz

    printf("isminiz: %s\n", isim15); //isim dizisini ekrana yazdırıyoruz
    printf("isminiz: %s\n", isim16); //isim dizisini ekrana yazdırıyoruz*/


    //--------------------------------------------------------------------------------


    //strrev() fonksiyonu
    char isim17[] = "mercedes";
     //strrev fonksiyonu karakter dizisini ters çevirir
    printf("%s\n", strrev(isim17)); //isim17 dizisini ekrana yazdırdık

    //strupr() fonksiyonu string upper
    char isim18[] = "mercedes";
   //strupr fonksiyonu karakter dizisini büyük harfe çevirir
    printf("%s\n",strupr(isim18) ); //isim18 dizisini ekrana yazdırdık

    //strlwr() fonksiyonu
    char isim19[] = "MERCEDES";
     //strlwr fonksiyonu karakter dizisini küçük harfe çevirir
    printf("%s\n",strlwr(isim19) ); //isim19 dizisini ekrana yazdırdık
/*
    //strstr() fonksiyonu
    char isim20[] = "mercedes";
    char isim21[] = "mer";
    printf("%s\n", strstr(isim20, isim21)); //strstr fonksiyonu karakter dizilerini karşılaştırır ve belirtilen karakter dizisini arar ve bulursa bulunduğu yeri döndürür

    */


    return 0;
}


