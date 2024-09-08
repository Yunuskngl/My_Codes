#include <stdio.h>
#include <stdlib.h>

struct kontrol1{
    int x;
    char y;
    double z;
};

union kontrol2{
    int a;
    char b;
    //double c;  // 8byte
};

int main(){
    printf("struct : %d ",sizeof(struct kontrol1));
    printf("union : %d ",sizeof(union kontrol2));
    return 0;
}