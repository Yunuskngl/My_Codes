#include <iostream>

using namespace std;

void tersCevir(char *c, int first, int last) {
    if (first < last) {
        char temp = c[first];
        c[first] = c[last];
        c[last] = temp;

        tersCevir(c, first + 1, last - 1);
    }
}

int main() {
    const int max_length = 100;
    cout << "Bir cumle girin: ";
    char cumle[max_length];
    cin.getline(cumle, max_length);
    tersCevir(cumle, 0, strlen(cumle) - 1);
    cout << "Ters cevirilmis hali: " << cumle << endl;
    return 0;
}
