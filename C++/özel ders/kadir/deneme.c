#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define isim_uzunluk 10
#define ders_not 5

typedef struct{
    char isim[isim_uzunluk];
    char soyad[isim_uzunluk];
    int numara;
    int not[ders_not];
} ogrenci;

void ogrenci_ekle(FILE *file);
void ogrenci_görüntüle(FILE *file);
void ogrenci_ara(FILE *file);
void ogrenci_güncelle(FILE *file);
void ogrenci_sil(FILE *file);

int main(){
    int seçenek;
    FILE *filep;

    while(1){
        printf("\n\n");
        printf("1.öğrenci ekle\n");
        printf("2.öğrenci görüntüle\n");
        printf("3.öğrenci ara\n");
        printf("4.öğrenci notunu değiştir\n");
        printf("5.öğrenci sil\n");
        scanf("%d",&seçenek);

        switch(seçenek){
            case 1:
                filep = fopen("ogrenci.txt","a+");
                if(filep==NULL ){
                    printf("dosya açılmadı");
                    return 1;
                }
                ogrenci_ekle(filep);
                fclose(filep);
                break;

            case 2:
                filep = fopen("ogrenci.txt","r");
                if(filep==NULL){
                    printf("dosya okunmadı");
                    return 1;
                }
                ogrenci_görüntüle(filep);
                fclose(filep);
                break;

            case 3:
                filep = fopen("ogrenci.txt","r");
                if(filep==NULL){
                    printf("dosya açılmadı");
                    return 1;
                }
                ogrenci_ara(filep);
                fclose(filep);
                break;

            case 4:
                filep = fopen("ogrenci.txt","r+");
                if(filep==NULL){
                    printf("dosya açılmadı");
                    return 1;
                }
                ogrenci_güncelle(filep);
                fclose(filep);
                break;

            case 5: 
                filep = fopen("ogrenci.txt","r+");
                if(filep==NULL){
                    printf("dosya açılmadı");
                    return 1;
                }
                ogrenci_sil(filep);
                fclose(filep);
                break;

            default:
                printf("geçersiz bir sayı seçtiniz. ");
                break;
        }
    }

    return 0;
}

void ogrenci_ekle(FILE *file) {
    ogrenci ogrenci;
    printf("öğrenci adı: ");
    scanf("%s", ogrenci.isim);
    printf("soyadı: ");
    scanf("%s", ogrenci.soyad);
    printf("öğrenci numarası: ");
    scanf("%d", &ogrenci.numara);

    for (int i = 0; i < ders_not; i++) {
        printf("ders %d notu: ", i + 1);
        scanf("%d", &ogrenci.not[i]);
    }

    // Metin formatında dosyaya yazma
    fprintf(file, "%s %s %d ", ogrenci.isim, ogrenci.soyad, ogrenci.numara);
    for (int i = 0; i < ders_not; i++) {
        fprintf(file, "%d ", ogrenci.not[i]);
    }
    fprintf(file, "\n");  // Her öğrenci için yeni satır
    printf("Öğrenci başarıyla eklendi.\n");
}

void ogrenci_görüntüle(FILE *file) {
    ogrenci ogrenci;
    rewind(file);
    printf("\nTüm öğrenciler : \n");

    // Metin formatında dosyadan okuma
    while (fscanf(file, "%s %s %d", ogrenci.isim, ogrenci.soyad, &ogrenci.numara) != EOF) {
        printf("adı : %s , soyadı : %s , numara: %d \n", ogrenci.isim, ogrenci.soyad, ogrenci.numara);
        for (int i = 0; i < ders_not; i++) {
            fscanf(file, "%d", &ogrenci.not[i]);
            printf("ders %d notu : %d\n", i + 1, ogrenci.not[i]);
        }
        printf("\n\n");
    }
}

void ogrenci_ara( FILE *file){
    int no;
    ogrenci ogrenci;
    int k=0;

    printf("aramak istediğiniz öğrenci numarasını giriniz : ");
    scanf("%d",&no);

    rewind(file);
    while(fscanf(file, "%s %s %d", ogrenci.isim, ogrenci.soyad, &ogrenci.numara) != EOF){
        for (int i = 0; i < ders_not; i++) {
            fscanf(file, "%d", &ogrenci.not[i]);
        }

        if(ogrenci.numara == no){
            printf("adı: %s , soyad: %s , no: %d \n",ogrenci.isim,ogrenci.soyad,ogrenci.numara);
            for(int i=0;i<ders_not; i++){
                printf("ders %d notu : %d \n",i+1,ogrenci.not[i]);
            }
            k++;
            break;
        }
    }
    if(k==0){
        printf("öğrenci bulunamadı\n");
    }
}

void ogrenci_güncelle(FILE *file){
    int no;
    ogrenci ogrenci;
    int k=0;
    FILE *temp;

    printf("aramak istediğiniz öğrenci numarasını giriniz : ");
    scanf("%d",&no);

    temp = fopen("temp.txt", "w");
    if(temp == NULL){
        printf("Geçici dosya açılamadı.\n");
        return;
    }

    rewind(file);
    while(fscanf(file, "%s %s %d", ogrenci.isim, ogrenci.soyad, &ogrenci.numara) != EOF){
        for (int i = 0; i < ders_not; i++) {
            fscanf(file, "%d", &ogrenci.not[i]);
        }

        if(ogrenci.numara == no){
            printf("öğrenci bulundu. yeni notları giriniz: \n");
            for(int i=0;i<ders_not ;i++){
                printf("ders %d notu :",i+1);
                scanf("%d",&ogrenci.not[i]);
            }
            k++;
        }

        fprintf(temp, "%s %s %d ", ogrenci.isim, ogrenci.soyad, ogrenci.numara);
        for (int i = 0; i < ders_not; i++) {
            fprintf(temp, "%d ", ogrenci.not[i]);
        }
        fprintf(temp, "\n");
    }

    fclose(file);
    fclose(temp);

    remove("ogrenci.txt");
    rename("temp.txt", "ogrenci.txt");

    if(k==0){
        printf("öğrenci bulunamadı\n");
    }
    else{
        printf("öğrenci notları güncellendi\n");
    }
}

void ogrenci_sil(FILE *file){
    int no;
    ogrenci ogrenci;
    FILE *temp;
    int k=0;

    printf("silmek istediğiniz öğrenci numarasını giriniz: ");
    scanf("%d",&no);

    temp=fopen("temp.txt","w");
    if(temp==NULL){
        printf("dosya oluşturulamadı");
        return ;
    }
    rewind(file);
    while(fscanf(file, "%s %s %d", ogrenci.isim, ogrenci.soyad, &ogrenci.numara) != EOF){
        for (int i = 0; i < ders_not; i++) {
            fscanf(file, "%d", &ogrenci.not[i]);
        }

        if(ogrenci.numara!= no){
            fprintf(temp, "%s %s %d ", ogrenci.isim, ogrenci.soyad, ogrenci.numara);
            for (int i = 0; i < ders_not; i++) {
                fprintf(temp, "%d ", ogrenci.not[i]);
            }
            fprintf(temp, "\n");
        }
        else{
            k++;
        }
    }
    fclose(file);
    fclose(temp);

    remove("ogrenci.txt");
    rename("temp.txt","ogrenci.txt");

    if(k==0){
        printf("öğrenci bulunamadı\n");
    }
    else{
        printf("öğrenci başarıyla silindi\n");
    }
}
