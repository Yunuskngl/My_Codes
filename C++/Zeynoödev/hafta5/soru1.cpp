
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, firstDigit, lastDigit, digits;
    cout << "Enter any number: ";  // kullanıcıdan sayı alıyoruz
    cin >> num;  // sayıyı alıyoruz
    lastDigit = num % 10;  // son basamağı alıyoruz
    digits = (int)log10(num);  // basamak sayısını alıyoruz
    firstDigit = (int)(num / pow(10, digits));  // ilk basamağı alıyoruz ve burada pow fonksiyonu şu işlemi yapar: 10 üzeri digits
    cout << "First digit = " << firstDigit << endl;  // ilk basamağı yazdırıyoruz
    cout << "Last digit = " << lastDigit << endl;  // son basamağı yazdırıyoruz
    return 0; // programı sonlandırıyoruz
}

