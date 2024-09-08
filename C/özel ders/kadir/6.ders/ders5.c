#include <stdio.h>
#include <stdlib.h>

void listele(int sayi){
    if(sayi == 0){
        printf("%d",sayi);
    }
    else{
        printf("%d\n",sayi);
        listele(sayi-1);
    }
}



int main(){
    int n; 
    printf("lutfen bir sayi girin\n");
    scanf("%d",&n);
    listele(n);
    return 0; 
}