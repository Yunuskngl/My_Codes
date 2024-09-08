#include <stdio.h>
#include <stdlib.h>

struct test{
    int x;
    double y;
    char a ;
};

int main(){
    struct test u;
    u.x = 2;
    u.y = 8.234234234234;
    printf("%d \n",u.x);
    printf("%lf\n",u.y);

    printf("uninon 'muzun tuttuğu alan %d bytetir ",sizeof(u));
    
}