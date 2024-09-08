
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, firstDigit, lastDigit;
    cout << "Enter any number: ";
    cin >> num;
    lastDigit = num % 10;
    while (num >= 10)
    {
        num = num / 10;
     
    } 
    firstDigit = num;
    cout << "First digit = " << firstDigit << endl;
    cout << "Last digit = " << lastDigit << endl;
    return 0;
}
