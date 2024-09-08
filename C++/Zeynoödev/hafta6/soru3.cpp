/*Write a C++ program to print all odd number between 1 to 100. Logic to print odd numbers is similar to logic to print even numbers. Step by step descriptive logic to print odd numbers from 1 to n. 1. Input upper limit to print odd number from user. Store it in some variable say N. 2. Run a loop from 1 to N, increment loop counter by 1 in each iteration. The loop structure should look like for(i=1; i<=N; i++). 3. Inside the loop body check odd condition i.e. if a number is exactly divisible by 2 then it is odd. Which is if(i % 2 != 0) then, print the value of i.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "Odd numbers between 1 to " << n << " are: ";
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    return 0;
}
