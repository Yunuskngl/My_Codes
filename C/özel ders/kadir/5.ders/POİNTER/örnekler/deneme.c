#include <stdio.h>
#include <stdlib.h>

void bastir(int *arr,int n){
    printf("degerlerim : \n");
    for(int i = 0; i<n ; i++){
        printf("%d ", *arr);
        arr++;
    }
}


int main(){
    int source_arr[100];
    int dest_arr[100];
    int n;
    int *source_ptr;
    int *dest_ptr;
    int *end_ptr;

    source_ptr = source_arr;
    dest_ptr = dest_arr;

    printf("dizi kaç elemanlı olsun? \n");
    scanf("%d",&n);

    printf("lütfen elemanları giriniz\n");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",(source_ptr+i));
    }
    end_ptr = &source_arr[n-1];
    printf("Kaynak arrayim kopyalamadan önce");
    bastir(source_arr,n);
    while(source_ptr <= end_ptr){
        *dest_ptr = *source_ptr;
        source_ptr++;
        dest_ptr++;
    }
    printf("\n kopyalandıktan sonraki source array : \n");
    bastir(source_arr,n);
    printf("\nkopyalandıktan sonra destination array : \n");
    bastir(dest_arr,n);
    return 0;

}