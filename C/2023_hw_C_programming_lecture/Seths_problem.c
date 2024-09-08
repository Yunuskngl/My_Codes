#include <stdio.h>
#include <stdlib.h>
#define size 5
int array_one[size];
int array_two[size];
int array_three[size];
int *ptr1 = array_one;
int *ptr2 = array_two;
int *ptr3 = array_three;


void inputseth(int array[size]){
    int *ptr = array;
    printf("Enter value for seth from 1 to 10000 ");
    for (int k = 0; k < 5; ++k)   scanf("%d", ptr + k);
}

void printseth(int array[size],int i){
    int *ptr = array;
    printf("Seth-%d",i);
    for (int k = 0; k < 5; ++k)   printf("%d", *(ptr + k));
}

