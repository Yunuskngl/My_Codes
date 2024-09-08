/*Yusuf decided to take a Kundura Tour which is a Summer Camp classic. But he doesn't realize that there is always something he has to take into account: MOVIE SETS!

Fortunately, his friend Emre warned him before he set off that he is not allowed to enter the movie sets and reminded Yusuf that he had to draw a logical route.

Yusuf has a map to use when planning his route. This map is represented as a grid (
a
r
r
) of cells, and each cell can contain one of the following four characters:

'a' : A place worth seeing

'b': A place with a movie set

'i': place of inzva

'.': empty place

Yusuf's goal is to find a rectangular area with one corner fixed at place of inzva, 
i
. In this rectangle, he wants to include as many 
′
a
′
 characters as possible while keeping the number of 
′
b
′
 characters as low as possible. Specifically, he wants to find the rectangle where the value of (number of 
′
a
′
s - number of 
′
b
′
s) is the highest. Can you help Yusuf to find the most logical area?

Note: There is only one place of inzva, 
i
.

Input Format
The first line contains 
N
,
M
 — number of rows and columns respectively.

The next lines contain, 
N
 rows and 
M
 columns, 
a
r
r
i
 — which are the characters in the grid.

Output Format
Print a single integer — value of the most logical area, (number of 
′
a
′
s - number of 
′
b
′
s)

Constraints
1
≤
N
,
M
≤
10
3
a
r
r
i
 only contains 'i', 'a', 'b', '.'
Sample Input 1 
3 4 
aib.
....
bba.
Sample Output 1 
1
Sample Input 2 
3 3
aib
ba.
aa.
Sample Output 2 
3*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define MAX 1000005

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> prefix(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'a') {
                prefix[i][j] = 1;
            } else if(grid[i][j] == 'b') {
                prefix[i][j] = -1;
            }
            if(i > 0) {
                prefix[i][j] += prefix[i - 1][j];
            }
            if(j > 0) {
                prefix[i][j] += prefix[i][j - 1];
            }
            if(i > 0 && j > 0) {
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = i; k < n; k++) {
                for(int l = j; l < m; l++) {
                    int sum = prefix[k][l];
                    if(i > 0) {
                        sum -= prefix[i - 1][l];
                    }
                    if(j > 0) {
                        sum -= prefix[k][j - 1];
                    }
                    if(i > 0 && j > 0) {
                        sum += prefix[i - 1][j - 1];
                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// Path: C%2B%2B/algoleague_Algorithm_ques/movie_sets_in_kundura.cpp
