/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 
Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]


Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {  // matrix'i döndür
        int n = matrix.size();  // n'yi matrix'in boyutu olarak al
        for (int i = 0; i < n / 2; i++) {  // n/2'ye kadar dön
            for (int j = i; j < n - i - 1; j++) {   // i'den n-i-1'e kadar dön
                int temp = matrix[i][j];  // temp değişkenini oluştur
                matrix[i][j] = matrix[n - j - 1][i];  // matrix[i][j]'yi döndür
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];  // matrix[n-j-1][i]'yi döndür
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];    // matrix[n-i-1][n-j-1]'yi döndür
                matrix[j][n - i - 1] = temp;  // temp'i matrix[j][n-i-1]'ye ata

            }

        }

    }

};

int main() {
    Solution s;  // s nesnesi oluştur
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};    // matrix1'i oluştur
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};  // matrix2'yi oluştur
    s.rotate(matrix1);  // matrix1'i döndür
    s.rotate(matrix2);  // matrix2'yi döndür
    for (int i = 0; i < matrix1.size(); i++) {  // matrix1'in boyutu kadar dön
        for (int j = 0; j < matrix1[i].size(); j++) {  // matrix1'in boyutu kadar dön
            cout << matrix1[i][j] << " ";  // matrix1'i yazdır
        }
        cout << endl;  
    }
    cout << endl; 
    for (int i = 0; i < matrix2.size(); i++) {  // matrix2'nin boyutu kadar dön
        for (int j = 0; j < matrix2[i].size(); j++) {  // matrix2'nin boyutu kadar dön
            cout << matrix2[i][j] << " ";  // matrix2'yi yazdır
        }
        cout << endl;
    }
    return 0;
}



