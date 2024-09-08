#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char isim[20];
    float agirlik;
    char form[20];
    int sayi;
    float fiyat;
}meyve;

typedef struct{
    meyve f[2];
}sepet;
                            
void meyveyi_olustur(meyve *yns){
    printf("meyvenin adini giriniz: \n");
    scanf("%s",yns->isim);
    printf("meyvenin agirliğini giriniz: \n");
    scanf("%f",&yns->agirlik);
    printf("meyvenin formunu giriniz : \n");
    scanf("%s",yns->form);
    printf("meyvenin sayisini giriniz : \n");
    scanf("%d",&yns->sayi);
    printf("meyvenin fiyatini giriniz : \n");
    scanf("%f",&yns->fiyat);
}

void sepeti_olustur(sepet *kadir){
    int i;
    for(i = 0 ; i< 2; i++){
        meyveyi_olustur(&kadir->f[i]);
    }
}

void agirligi_hesapla(sepet can , float *total){
    *total = 0;
    for(int i = 0; i< 2; i++){
        *total  = *total + (can.f[i].agirlik * can.f[i].sayi);
    }
}

void fiyati_hesapla(sepet can , float *total){
    *total = 0;
    int i ;
    float seklegore = 0;
    for(i = 0; i< 2 ;i++){
        seklegore = can.f[i].fiyat;
        if(strcmp(can.f[i].form , "yuvarlak") == 0){
            seklegore = seklegore*2;
        }
        if(can.f[i].agirlik >200){
            seklegore = seklegore+3;
        }
        *total = *total + (seklegore*can.f[i].sayi);
    }
}

int main(){
    float a,b;
    sepet kadir;
    sepeti_olustur(&kadir);
    agirligi_hesapla(kadir,&a);
    fiyati_hesapla(kadir,&b);
    printf("toplam  agirlik : %f \n" , a);
    printf("toplam fiyat  : %f ", b);
    return 0;
}
