#include <stdio.h>
#include <stdlib.h>

int ara(int *arr,int size, int tosearch){
    int index = 0 ; 
    int *arrEnd;
    arrEnd = (arr + size -1);
    while(arr <= arrEnd && *arr  != tosearch){
        arr++;
        index++;
    }
    if(arr <= arrEnd){
        return index;
    }
    return -1;
}

void degeralma(int *array,int size){
    int *arrend;
    arrend = (array +size -1);
    while(array <= arrend){
        scanf("%d",array++);
    }
}







int main(){
    int array[100];
    int size, search , searchindex;

    printf("dizimiz kaç elemanlı olsun");
    scanf("%d",&size);

    printf("dizimizin elemanları : \n");
    degeralma(array,size);
    printf("hangi elemanı ariyoruz\n");
    scanf("%d",&search);
    searchindex = ara(array,size,search);
    if(searchindex == -1){
        printf("%d elemanı dizide yok!!!!",search);
    }
    else{
        printf("%d elemanı %d pozisyonunda bulunuyor",search,searchindex+1);
    }
    return 0 ; 

}