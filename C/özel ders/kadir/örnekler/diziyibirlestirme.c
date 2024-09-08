#include <stdio.h>
#include <stdlib.h>

void diziyibirlestirme(int array1[],int array2[],int array3[],int s1,int s2){
    int sayac = 0;
    for(int i = 0 ; i<s1 ; i++){
        array3[sayac] = array1[i];   
        sayac++;                     
    }
    for(int j=0 ; j<s2 ; j++){
        array3[sayac] = array2[j];
        sayac++;
    }

}

void diziyiyazdirma(int array[],int size){
    for(int i = 0 ; i< size ; i++){
        printf("%d ", array[i]);
    }
}



int main(){
    int size1, size2;
    printf("sırasıyla değerleri giriniz. \n");
    scanf("%d%d",&size1,&size2);

    int arr1[size1] , arr2[size2];

    printf("array1 in elemanlarını giriniz \n");
    for(int i = 0 ; i< size1 ;i++){
        scanf("%d",&arr1[i]);
    }

    printf("array2 in elemanlarını giriniz..");
    for(int j= 0 ; j<size2 ; j++){
        scanf("%d",&arr2[j]);
    }

    int arr3[size1+size2];

    diziyibirlestirme(arr1, arr2,arr3,size1,size2);

    diziyiyazdirma(arr3,size1+size2);




    return 0;
}