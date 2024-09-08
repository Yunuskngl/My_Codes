#include <stdio.h>
#include <stdlib.h>

//fibonacci serisi

int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fibonacci(3) + fibonacci(2);   // fibonacci(1) + fibonacci(0) = 1 + 0 = 1    n=2
                                                    // fibonacci(2) + fibonacci(1) = 1 + 1 = 2  n=3
                                                    // fibonacci(3) + fibonacci(2) = 2 + 1 = 3  n = 4
                                                    // fibonacci(4) + fibonacci(3) = 3 + 2 = 5
                                                    // fibonacci(5) + fibonacci(4) = 5 + 3 = 8
                                                    // fibonacci(6) + fibonacci(5) = 8 + 5 = 13
                                                    // fibonacci(7) + fibonacci(6) = 13 + 8 = 21
                                                    // fibonacci(8) + fibonacci(7) = 21 + 13 = 34
                                                    // fibonacci(9) + fibonacci(8) = 34 + 21 = 55
                                                    // fibonacci(10) + fibonacci(9) = 55 + 34 = 89
                                                                                                      
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("%d ", fibonacci(i));
    }
    return 0;
}



