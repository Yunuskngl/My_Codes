#include <stdio.h>  // Standart giriş çıkış fonksiyonlarını kullanabilmek için gerekli kütüphane

// main fonksiyonu programın başlangıç noktasıdır
int main() {  

    
    int num1 = 5;   // Tam sayı değişkeni.  4 byte yer kaplar. -2^31 ile 2^31 sayıları arasında değer alabilir. 
    float num2 = 3.5; // Ondalıklı sayı değişkeni. 4 byte yer kaplar. 1.2e-38 ile 3.4e38 arasında değer alabilir.
    double num3 = 7.3;  // Çift hassasiyetli ondalıklı sayı değişkeni. 8 byte yer kaplar. 2.3e-308 ile 1.7e308 arasında değer alabilir.
    char ch = 'A';  // Karakter değişkeni. 1 byte yer kaplar. 
  

/*
   
   
    printf("num1: %d\n", num1); // Standart çıkış fonksiyonu. Ekrana yazdırma işlemi yapar.
    printf("num2: %f\n", num2); 
    printf("num3: %lf\n", num3);
    printf("ch: %c\n", ch);
   

   
    int deger;
    printf("Bir sayı girebilir misin ?: ");
    scanf("%d", &deger); // Standart giriş fonksiyonu. Kullanıcıdan veri alır.
    printf("Girilen sayı: %d\n", deger);


    //--------------------------------------------------------------------------------------
*/
    // Aritmetik operatörler
    int sum = num1 + num2;  // Toplama işlemi
    int difference = num1 - num2; // Çıkarma işlemi
    int product = num1 * num2; // Çarpma işlemi
    double division = (double)num1 / num2; // Tip dönüşümü ve bölme işlemi   
    printf("Sum: %d\n", sum); 
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Division: %.2f\n", division); 

    //bir sayının diğer sayıya bölümünden kalanı bulmak için "%" operatörünü kullanırız.
    int sonuc = 20 % 3 ; // sonuc = 2 olacaktır.

    return 0; 

}