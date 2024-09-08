
#include <iostream>
#include <string>
using namespace std;

int main()
{
    
string cumle;    cout << "Bir cumle giriniz: ";
    getline(cin, cumle);
    for (int i = 0; i < cumle.length(); i++)
    {
        if (cumle[i] >= 'a'   && cumle[i] <= 'z')
            cumle[i] = cumle[i] - 32;  
    }                  
    cout << "Cumle: " << cumle << endl;
    return 0;
}
