//karakter dizileri
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //string.h kütüphanesini ekledik

int main() {

    //tanımlama
    char yns[5] = {'y', 'n', 's', 'a', '\0'}; //yns adında 5 karakterlik bir dizi tanımladık ve içine "ynsa" yazdık
    char yns2[5] = "ynsa"; //yns2 adında 5 karakterlik bir dizi tanımladık ve içine "ynsa" yazdık


    char array[] = "MERHABALAR DÜNYA";  //16*1byte
    array[0] = 'O'; //array dizisinin 0. elemanını 'O' olarak değiştirdik
    printf("%s\n", array); //array dizisini ekrana yazdırdık

  


    //karakter dizilerini ekrana yazdırma
    char isim[20]; //isim adında 20 karakterlik bir dizi tanımladık   20*1"=20 byte yer kaplar
    printf("isminizi giriniz: ");
    gets(isim); //kullanıcıdan isim alıyoruz
    printf("isminiz: %s\n", isim); //isim dizisini ekrana yazdırıyoruz

    


    //karakter dizilerini ekrana yazdırma
    char isim2[20] = "kadir"; //isim2 adında 20 karakterlik bir dizi tanımladık ve içine "kadir" yazdık
    printf("isim2: %s\n", isim2); //isim2 dizisini ekrana yazdırıyoruz


    return 0;
}
