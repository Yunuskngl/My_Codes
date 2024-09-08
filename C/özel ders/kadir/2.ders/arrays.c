#include <stdio.h>
#include <stdlib.h>


int main()
{
    //ARRAYS          
    int numbers[5] = {121312, 2213213, 31232135, 4213123,3125};  //5*4byte  = 20 byte yer kaplar
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};  //5*1byte = 5 byte yer kaplar
    float decimals[5] = {1.1, 2.2, 3.3, 4.4, 5.5};  //5*4byte = 20 byte yer kaplar

    //Accessing elements of an array
    printf("%d\n", numbers[0]);
    printf("%c\n", letters[1]);
    printf("%f\n", decimals[2]);



    //Arraydeki elemanı değiştirme
    numbers[0] = 10;
    letters[1] = 'Z';
    decimals[2] = 10.5;

    printf("%d\n", numbers[0]);
    printf("%c\n", letters[1]);
    printf("%f\n", decimals[2]);


    printf("---------------------------------------------------\n");
    //Arraydeki elemanları yazdırma
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", numbers[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", letters[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", decimals[i]);
    }

    return 0;
}

