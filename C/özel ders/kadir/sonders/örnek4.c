#include <stdio.h>
#include <math.h>

struct nokta{
    float x; 
    float y;
};

float uzaklik (struct nokta n1,  struct nokta n2){
    return sqrt(pow(n2.x - n1.x,2) + pow(n2.y-n1.y,2));
}

int main(){
    struct nokta yns  = {2,3};
    struct nokta kadir = {5,7};

    printf("nokta 1 : (%.2f ,%.2f)\n",yns.x,yns.y);
    printf("nokta 2 : (%.2f ,%.2f)\n",kadir.x,kadir.y);
    printf("uzaklik : %.2f\n",uzaklik(yns,kadir));
}