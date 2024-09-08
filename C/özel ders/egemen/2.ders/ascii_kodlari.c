#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ASCII KODLARI
    char ch = 'A';  //ASCII kodu 65
    printf("%d\n", ch);

    char ch2 = 'a';  //ASCII kodu 97
    printf("%d\n", ch2);

    char ch3 = '0';  //ASCII kodu 48
    printf("%d\n", ch3);

    char ch4 = ' ';  //ASCII kodu 32
    printf("%d\n", ch4);

    char ch5 = '\n';  //ASCII kodu 10
    printf("%d\n", ch5);


    //ASCII KODLARINI KULLANARAK BİR DİZİYİ YAZDIRMA

    for (int i = 65; i <= 90; i++)
    {
        printf("%c\n", i);
    }
    



    

    return 0;
}