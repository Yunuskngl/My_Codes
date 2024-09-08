#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void bubble(int size,int arry[]){
int i,j,z=0;


for(i=0;i<size -1 ;i++){
    for (j=1 ; j < size - 1 -i ; j++){
        if (arry[j] > arry[j+1])
        {
            z = arry[j];
            arry[j] = arry[j+1];
            arry[j+1] = z;



        }
        
    }
    
}




for(i=0;i<size;i++){
    printf("%d ",arry[i]);
}
}

int main(){
int size,i;


printf("enter a number: ");
scanf("%d",&size);
int arr[size];

for(i=0;i < size;i++){
printf("enter a number: ");
scanf("%d",&arr[i]);
}

bubble(size,arr);
    return 0;
}