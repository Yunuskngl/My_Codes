#include <iostream>
using namespace std;
bool isAsal(int num, int i = 2) {
    if (num <= 2)
        return (num == 2);
    if (num % i == 0)
        return 0;
    if (i * i > num)
        return 1;
    return isAsal(num, i + 1);   //0 1 
}
void listeleAsal(int n, int current = 2) {
    if (current <= n) {
        if (isAsal(current))
            cout << current << " ";

        listeleAsal(n, current + 1);
    }
}
int main() {
    int N;
    cout << "N pozitif tam sayisini girin: ";
    cin >> N;
    cout << "1 ile " << N << " arasindaki asal sayilar:\n";
    listeleAsal(N);
    return 1;
}
