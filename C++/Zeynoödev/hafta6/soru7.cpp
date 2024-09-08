/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.


Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {  // string s al
        int len = 0;  // len değişkenini oluştur
        for (int i = s.size() - 1; i >= 0; i--) {  // sondan başa doğru dön
            if (s[i] == ' ' && len > 0) {  // eğer boşluk ve len > 0 ise
                return len;  // len'i döndür
            } else if (s[i] != ' ') {  // eğer boşluk değilse
                len++;  // len'i arttır
            }
        }
        return len;  // len'i döndür
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;  // "Hello World" için lengthOfLastWord fonksiyonunu çağır
    cout << s.lengthOfLastWord("   fly me   to   the moon  ") << endl;  // "   fly me   to   the moon  " için lengthOfLastWord fonksiyonunu çağır
    cout << s.lengthOfLastWord("luffy is still joyboy") << endl;  // "luffy is still joyboy" için lengthOfLastWord fonksiyonunu çağır
    return 0;
}
