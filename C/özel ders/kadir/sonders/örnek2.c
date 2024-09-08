/*


problem : bir sınıfta bulunan öğrencilerden hangisinin boyunun 150 cm ye en yakın olduğunu bulunuz.
bu program öğrenci numaralarını ve santimetre cinsinden girdi olarak alır . öğrenci numarası negatif olana dek sayı girişi devam eder.

*/

#include <stdio.h>
#include <stdlib.h>

int en_yakin_boy(int numara_boy[][2],int num_students){
    int en_yakin_index = 0;
    for(int i=1 ; i< num_students ; i++){
        if(abs(numara_boy[i][1]-150) < abs(numara_boy[en_yakin_index][1]-150)){
            en_yakin_index = i;
        }
    }
    return en_yakin_index;
}





int main(){
    int ogrenci_numara_boy[100][2];
    int num_students = 0;
    int numara,boy;
    
    while(1){
        printf("Öğrenci numarasını girin(negatif sayı olmasın)");
        scanf("%d",&numara);
        if(numara<0){
            break;
        }
        printf("öğrenci boyunu santimetre olarak gir:");
        scanf("%d",&boy);
        ogrenci_numara_boy[num_students][0] = numara;
        ogrenci_numara_boy[num_students][1] = boy;
        num_students++;
    }
    
    int en_yakin_index = en_yakin_boy(ogrenci_numara_boy,num_students);
    printf("150 cm e en yakın ögrenci numarası : %d , boyu : %d cm\n",ogrenci_numara_boy[en_yakin_index][0],ogrenci_numara_boy[en_yakin_index][1]);



    return 0;
}


 

