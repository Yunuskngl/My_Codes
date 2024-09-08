/*Bir pozitif tamsayı olan n değeri ile bir reel sayı olan x değerini girdi olarak alan ve  
x^2/1! + x^3/2! + x^4/3! + ….. + x^(n+1)/n!  serisini hesaplayan program yazınız.
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    float x, toplam = 0, carpim = 1;
    cout << "n degerini giriniz: ";
    cin >> n;
    cout << "x degerini giriniz: ";
    cin >> x;
    for(int i = 1; i <= n; i++){
        carpim *= i;
        toplam += (x * x) / carpim;
    }
    cout << "Sonuc: " << toplam << endl;
    return 0;
}