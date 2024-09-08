#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char isim[10];
    float xekseni;
    float yekseni;

}nokta;

void ekranayazdir(nokta p[] ,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%s = (%.2f,%.2f)\n",p[i].isim,p[i].xekseni,p[i].yekseni);
    }
}


int main(){
    nokta yns[5] = {{"Can",5,4},{"hakan",5,3},{"osman",5,1},{"kadir",1,3},{"hasan",8,9}};
    ekranayazdir(yns,5);
    return 0;
}