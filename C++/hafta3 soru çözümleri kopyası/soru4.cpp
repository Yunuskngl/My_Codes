#include <iostream>
using namespace std;
int main() {
    int can[5];
    int *sayi1, *sayi2;
    int n;
    int gecici;

    cout << "Lutfen dizimizin eleman sayisini giriniz\n";
    cin >> n;

    for (sayi1 = can; sayi1 < can + n; sayi1++) {
        cout << "Lutfen eleman giriniz:\n";
        cin >> *sayi1;
    }

    cout << "Dizimizin ilk hali";

    for (sayi1 = can; sayi1 < can + n; sayi1++) {
        cout << " " << *sayi1;
    }

    cout << "\n";

    for (sayi1 = can, sayi2 = can + n - 1; sayi1 < sayi2; sayi1++, sayi2--) {
        gecici = *sayi1;
        *sayi1 = *sayi2;
        *sayi2 = gecici;
    }

    cout << "Dizimizin elemanlari yer degistirdikten sonra :";

    for (sayi1 = can; sayi1 < can + n; sayi1++) {
        cout << " " << *sayi1;
    }

    cout << "\n";

    return 0;
}

