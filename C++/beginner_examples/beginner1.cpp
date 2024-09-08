#include <iostream>
using namespace std;
#define pi 3.14


/*daire alan: 

int main(){
    int a;
    cout << "enter number:" << endl;
    cin  >> a ; 
    cout << a*a*pi << endl ; 
 }

*/

/*Küp yanal alanlar toplamı ve hacim : 

int main(){
    int a;
    cout  << "enter number:" << endl;
    cin >> a ; 
    cout << endl;
    cout << "yanal alanlar toplami: "   << a * a * 6 << endl; 
    cout << "hacim: " << a*a*a << endl;

}
*/

/*String kullanımı : */
int main(){
    string isim,soyisim,age,number; 
    cout << "enter name,surname,age and number : " << endl;
    cin >> isim >> soyisim >> age >> number ; 

    cout << "info: " << endl << isim  << " " << soyisim << " " <<" " << age << " " << number  ; 
}
