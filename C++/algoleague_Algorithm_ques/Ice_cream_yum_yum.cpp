#include <stdio.h>

//https://algoleague.com/problem/ice-cream-yum-yum/detail

int main() {
	int min ; 

	int n; 
	int sum=0;
	int i,j,k;

	scanf("%d",&n);	
	int arr[n];
	scanf("%d",&arr[0]);
	min  = arr[0];
	sum += arr[0];
	for(i  = 1; i < n; i++) {
        
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] < min) min = arr[i];
        
    }
    
    printf("%d",sum-min);
    

	return 0;
}