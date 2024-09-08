#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Dizi boyutunu girin: ";
    cin >> n;
    int* dizi = new int[n];
    cout << "Dizi elemanlarini girin:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Eleman " << i + 1 << ": ";
        cin >> dizi[i];
    }
    int* bas = dizi;
    int* son = dizi + n - 1;
    while (bas < son) {
        int gecici = *bas;
        *bas = *son;
        *son = gecici;
        bas++;
        son--;
    }
    cout << "Dizi elemanlari (basdan sona degistirilmis):\n";
    for (int i = 0; i < n; ++i) {
        cout << dizi[i] << " ";
    }
    delete[] dizi;
    return 0;
}
