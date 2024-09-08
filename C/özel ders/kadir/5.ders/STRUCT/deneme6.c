#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float xekseni ;
    float yekseni ; 

}nokta;

int main(){
    nokta yns;
  
    yns.xekseni = 1.5234325324234;
    yns.yekseni = 2.213123123213;

    printf("x ekseni : %.5f , y ekseni : %.5f ",yns.xekseni,yns.yekseni);


}