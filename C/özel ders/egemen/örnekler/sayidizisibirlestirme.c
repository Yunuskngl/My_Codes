#include <stdio.h>
#include <stdlib.h>

void birlestirme(int array1[] , int array2 [] ,int array3[],int size1,int size2){
    int sayac = 0;
    for(int i = 0; i<size1 ; i++){
        array3[sayac] = array1[i];
        sayac++;
    }
    for(int i = 0; i<size2 ; i++){
        array3[sayac] = array2[i];
        sayac++;
    }
    printf("birleştirilmiş hali : ");
    for(int i = 0; i<sayac; i++){
        printf(" %d " , array3[i]);
    }

    

    
}


int main(){
    int size1 ,size2;
    printf("sırasıyla bana değer giriniz ; ");
    scanf("%d%d",&size1,&size2);
    
    int arr1[size1];
    int arr2[size2];


    printf("lütfen 1. array için değer giriniz.\n");
    for(int i = 0; i<size1 ; i++){
        scanf("%d",&arr1[i]);
    }
    printf("\n");
    printf("lütfen 2. array için değer giriniz.\n");
    for(int i = 0; i<size2 ; i++){
        scanf("%d",&arr2[i]);
    }


    int arr3[size1+size2];

    birlestirme(arr1,arr2,arr3,size1,size2);


    
}