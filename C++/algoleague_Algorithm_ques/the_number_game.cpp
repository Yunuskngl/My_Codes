 /*oyunda Kekik ve Haydarberk sırayla oynarlar. Her turda, bir oyuncu 0 ile 1000 arasında bir sayı seçer ve diğer oyuncu bu sayıyı 1'e indirmeye çalışır. Bu stratejiye göre:

Eğer sayı çift ise, oyuncu sayıyı 2'ye böler.
Eğer sayı tek ise, oyuncu sayıyı 3 ile çarpar ve 1 ekler.
Bir oyuncu bu stratejiyi kullanarak sayıyı 1'e indirebildiğinde, bu tura tek sayıda adımda ulaşmış olur ve bir puan alır.

Oyun Kekik'in bir sayı seçmesiyle başlar, ardından Haydarberk bu sayıyı 1'e indirir. Sonraki turlarda ise Haydarberk bir sayı seçer ve Kekik bu sayıyı 1'e indirir. Bu şekilde tüm turar oynanır.

Verilen girdilere göre, Kekik'in mi yoksa Haydarberk'in mi kazandığını belirlemek için her turun toplam adım sayısının tek mi yoksa çift mi olduğuna bakarız. Eğer toplam adım sayısı çift ise Kekik kazanır, tek ise Haydarberk kazanır. Eğer tüm turar berabere biterse, yani her iki oyuncu da aynı sayıda turda 1'e ulaşırsa, berabere biter.

Örnek girişlerde verilen N sayısı tur sayısını belirtir ve sonraki satırlarda ise her turda seçilen sayılar yer alır. Örneğin, ilk örnekte Kekik ve Haydarberk arasında 4 tur oynanır ve her turda sırasıyla 2, 4, 6 ve 5 sayıları seçilir.

Sonuç olarak, Kekik'in mi, Haydarberk'in mi yoksa berabere mi kazandığını belirlemek için bir */

#include <iostream>
#include <string>
using namespace std;
//sırasıyla N kadar değer girilirken önce haydarberk 1. değer için işlem yapılcak sonra ikinci değer kekik için ve böyle sırasıyla gidecek
// iki total değerleri olcak önce haydarberk için total değeri toplicaz sonra kekik için total değeri toplıcaz
int main() {
    int N;
    cin >> N;
    int totalHaydarberk = 0;
    int totalKekik = 0;
    int i;
    while (i<N) {
        int x;
        cin >> x;
        int stepsHaydarberk = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x = x * 3 + 1;
            }
            stepsHaydarberk++;
        }
        if(stepsHaydarberk % 2 == 1){
            totalHaydarberk += stepsHaydarberk;
        }
        stepsHaydarberk = 0;
        i++;
        cin >> x;
        int stepsKekik = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x = x * 3 + 1;
            }
            stepsKekik++;
        }
        if(stepsKekik % 2 == 1){
            totalKekik += stepsKekik;
        }
        stepsKekik = 0;
        i++;
    }
    if (totalHaydarberk  == totalKekik) {
        cout << "DRAW" << endl;
    } 
    else if (totalHaydarberk < totalKekik) {
        cout << "HAYDARBERK" << endl;
    } else {
        cout << "KEKIK" << endl;
    }




    
    return 0;
}
