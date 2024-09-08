/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 
Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0; // ones ve twos değişkenlerini oluştur
        for (int i = 0; i < nums.size(); i++) {  // nums'in boyutu kadar dön
            ones = (ones ^ nums[i]) & ~twos;  // ones'i güncelle . ~twos, twos'un değilini alır
            twos = (twos ^ nums[i]) & ~ones;  // twos'u güncelle
        }
        return ones;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {2, 2, 3, 2};
    vector<int> v2 = {0, 1, 0, 1, 0, 1, 99};
    cout << s.singleNumber(v1) << endl;
    cout << s.singleNumber(v2) << endl;
    return 0;
}

