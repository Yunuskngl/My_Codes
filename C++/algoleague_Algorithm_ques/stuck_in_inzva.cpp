//SOLUTION: 

//https://algoleague.com/problem/day-1-stuck-in-inzva/detail

/*
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


string Duplicate(const string& str) {
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (isVowel(str[i])) {
            result += str[i];
            
            while (i + 1 < str.size() && str[i] == str[i + 1]) {
                i++;
            }
        } else {
            result += str[i];
        }
    }
    return result;
}

int main() {
    string book, keyword;
    cin >> book >> keyword;
    string cleanBook = Duplicate(book);
    string cleanKeyword = Duplicate(keyword);
    if (cleanBook.find(cleanKeyword) != string::npos) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}*/