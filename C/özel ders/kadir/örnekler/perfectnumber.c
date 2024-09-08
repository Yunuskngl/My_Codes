// 6   ->  1 2 3  

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("nereye kadar gidelim ? ");
    scanf("%d",&n);
    int toplam = 0;
    for(int i = 1 ; i<n ; i++){
        toplam = 0;
        for(int j = 0 ; j < i ; j++){
            if(i % j == 0){
                toplam += j;
            }
        }
        if(toplam == i){
            printf("%d\n",i);
        }

    }
    return 0;
}


// 1 2 4 7 14