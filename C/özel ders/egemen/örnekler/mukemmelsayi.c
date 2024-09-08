// 6  -> 1 2 3  mükemmmel sayi perfect number 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("nereye kadar kontrol edelim hocam? ");
    scanf("%d",&n);
    int toplam = 0 ; 
    for(int i = 0 ; i < n ; i++){
        toplam  = 0;
        for (int j = 0 ; j< i ; j++){
            if(i%j == 0){
                toplam += j;
            }
        }
        if(i == toplam){
            printf("%d\n",toplam);
        }
    }
    return 0;
}