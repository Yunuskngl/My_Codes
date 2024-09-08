#include <stdio.h>
#include <stdlib.h>

struct ogrencitip{
    int no;
    char cevap[10];
};

struct sonuctip{
    int no;
    int not;
};

int main(){
    struct ogrencitip ogrenci[30];
    struct sonuctip sonuc[30];
    char anahtar[30],satir;
    int i,j;
    int dogru,yanlis;
    printf("lütfen cevap anahtarını giriniz:\n");
    for(i = 0 ; i < 10 ; i++){
        scanf("%s",&anahtar[i]);
    }
    printf("ogrenci bilgilerini giriniz");
    for(j=0;j<30;j++){
        printf("ogrenci no: \n");
        scanf("%d",&ogrenci[j].no);
        dogru = yanlis = 0;
        scanf("%c",&satir);
        printf("cevaplari:");
        for( i = 0 ; i<10 ; i++){
            scanf("%s",&ogrenci[j].cevap[i]);
            if(anahtar[i] == ogrenci[j].cevap[i]){
                dogru++;
            }
            else if( ogrenci[j].cevap[i] != ' ' ){
                yanlis++;
            }
        }
        sonuc[j].no = ogrenci[j].no;
        printf("dogru : %d , yanlis : %d\n",dogru,yanlis);
        sonuc[j].not = dogru -(yanlis/4);

    }
    for(j = 0 ; j<30 ; j++){
        printf("ogrenci no : %d not : %d \n",sonuc[j].no,sonuc[j].not);
    }
    return 0; 
}
