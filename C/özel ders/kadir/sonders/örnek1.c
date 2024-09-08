//kullanıcıdan bir n değeri iste
//1+1/2+1/3+1/4+...+1/n toplamını hesapla
//do while ile çöz

#include <stdio.h>

int main(){
    int n;
    float toplam = 0;
    printf("n değerini giriniz: ");
    scanf("%d",&n);

    int i = 1;
    do
    {
        toplam += 1.0/i;
        i++;
    } while (i<=n);
    
    printf("toplam : %.2f",toplam);
    


    return 0;
}