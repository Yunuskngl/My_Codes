

//PROBLEM 1:
//Bir çiftlikte tavşanların sayısı 1042 iken,kuşların sayısı 2272’dir.Bir yılda tavşanlar %3.8 oranında çoğalırken,kuşlar %1.2 oranında çoğalmaktadır. Tavşanların kuşların sayısını kaç yıl sonra geçeceğini bulan bir C++ programı yazınız.
/*

#include <iostream>
using namespace std;

int main()
{
    int tavsan = 1042;
    int kus = 2272;
    int yil = 0;
    while (kus > tavsan)
    {
        tavsan = tavsan + tavsan * 0.038;
        kus = kus + kus * 0.012;
        yil++;
    }
    cout << "geçen yil : " << yil << endl;
    return 0;

}
*/

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//PROBLEM 2:

/*Bir pozitif tamsayı olan n değeri ile bir reel sayı olan x değerini girdi olarak alan ve 
1/x^2 + 3/x^4 + 5/x^6 + 7/x^8 + ... +2n-1/x^2n serisini hesaplayan program yazınız.
  Örnek çıktı:
  Pozitif tamsayı :3 
  Reel sayi: 1.0
  Seri: 9.00 */


#include <iostream>
using namespace std;
int main(){
    int n;
    float x;
    float toplam = 0;
    cout << "Pozitif tamsayi: ";
    cin >> n;
    cout << "Reel sayi: ";
    cin >> x;
    for (int i = 1; i <= 2 * n - 1; i += 2)
    {
        toplam += i / pow(x, i);
    }
/*
    while (n > 0)
    {
        toplam += 1 / pow(x, 2 * n);
        n--;
    }
*/
    cout << "Seri: " << toplam << endl;
    return 0;
}










