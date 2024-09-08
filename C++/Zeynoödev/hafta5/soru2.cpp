
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";  // eğer num 0 ise "Zero" döndürüyoruz
        vector<string> v1 = {"", "Thousand", "Million", "Billion"}; // 1000, 1000000, 1000000000 için
        vector<string> v2 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};   // birler basamağı için
        vector<string> v3 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; // onlar basamağı için
        vector<string> v4 = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};    // 10-19 arası için
        string res = ""; 
        int i = 0;
        while (num > 0) {  
            if (num % 1000 != 0) {  // burada 1000'e bölünmeyen kısmı işliyoruz
                res = helper(num % 1000, v2, v3, v4) + v1[i] + " " + res;  // 1000'e bölünmeyen kısmı helper fonksiyonuna gönderiyoruz . helper fonksiyonu şu işlemi yapıyor: 123 -> 123 % 100 = 23 -> 23 / 10 = 2 -> 2 % 10 = 2 -> v2[2] = "Two" -> "Two" döndürüyor
            }
            num /= 1000;  // 1000'e bölüyoruz
            i++;  // i'yi arttırıyoruz
        }
        while (res.back() == ' ') res.pop_back();   // sondaki boşlukları siliyoruz
        return res;  // sonucu döndürüyoruz
    }
    string helper(int num, vector<string>& v2, vector<string>& v3, vector<string>& v4) {  // helper fonksiyonu
        string res = "";   // sonucu tutacak string
        if (num >= 100) {   // 100'den büyükse
            res += v2[num / 100] + " Hundred ";   // yüzler basamağını alıyoruz
            num %= 100;
        }
        if (num >= 20) {  // 20'den büyükse
            res += v3[num / 10] + " ";  // onlar basamağını alıyoruz
            num %= 10;
        } 
        if (num >= 10) { // 10'dan büyükse
            res += v4[num - 10] + " ";  // 10'dan büyükse v4'ten alıyoruz
            return res;
        }
        if (num > 0) {  // 0'dan büyükse
            res += v2[num] + " ";  // v2'den alıyoruz
        }
        return res;  // sonucu döndürüyoruz
    }
};

int main() {
    Solution s;
    cout << s.numberToWords(123) << endl;  // test1
    cout << s.numberToWords(12345) << endl;  // test2
    cout << s.numberToWords(1234567) << endl;   // test3
    return 0;
}

