#include <stdio.h>

int f(int a,int b){
    if(a == 0) return b;
       
    return f(a-1,a+b);
}

int main(){
    int b = f(4,4);
    printf("%d",b);

}