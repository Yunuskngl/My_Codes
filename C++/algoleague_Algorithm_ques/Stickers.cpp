//https://algoleague.com/problem/stickers/detail

#include <bits/stdc++.h>

using namespace std;

long long multiply_digits_except_zeros(long long num) {
    long long sum = 1;
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0) {
            sum *= digit;
        }
        num /= 10;
    }
    return sum;
}

int get_result(long long n) {
    while (n >= 10) {
        n = multiply_digits_except_zeros(n);
    }
    return n;
}

int main() {

    long long n;
    cin >> n;


    cout << get_result(n) << endl;

    return 0;
}