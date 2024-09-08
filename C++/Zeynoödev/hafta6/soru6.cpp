/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
ü


Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {  // digits = "23"
            vector<string> temp;  
            string chars = dict[digits[i] - '2'];  // neden -2? çünkü '2' nin ascii değeri 50, '0' nin ascii değeri 48. 50-48 = 2
            for (int j = 0; j < chars.size(); j++) {  // 
                for (int k = 0; k < res.size(); k++) { // k = 0
                    temp.push_back(res[k] + chars[j]);  // temp = ["a"]
                }
            }
            res = temp;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> res1 = s.letterCombinations("23");
    vector<string> res2 = s.letterCombinations("");
    vector<string> res3 = s.letterCombinations("2");
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < res3.size(); i++) {
        cout << res3[i] << " ";
    }
    cout << endl;
    return 0;
}


