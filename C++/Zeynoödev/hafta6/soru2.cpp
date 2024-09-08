
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[10] = "abcde";
    revString(s);  // fonksiyonu çağırma

}

void revString(char* s) {
    int n = strlen(s);  // stringin uzunluğunu al
    for (int i = 0; i < n / 2; i++) {  // stringin yarısına kadar dön
        char temp = s[i];  // temp değişkeni oluştur
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    cout << s << endl;  // stringi yazdır
}