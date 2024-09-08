/*Mater loves scaring the tractors at the farm at night, and because McQueen loves Mater, he always joins him. However, if they scare too many tractors, the entire herd wakes up and chases after them.


You are given a farm represented as follows:

. represents grass
# represents fences
M represents tractors
A represents their initial position
Mater and McQueen can escape the farm through any grass tile on the edges of the farm. Tractors move optimally to catch them, but if Mater and McQueen encounter (i.e., share the same tile with) a tractor, they can't escape anymore, even when they are on an edge of the farm. Your task is to find the number of minimum moves they can escape, if they can not print -1.

Input Format
The first line includes two integers 
n
 and 
m
 — the number of rows and columns of the farm, respectively.

The next 
n
 lines each contain a string of length 
m
 representing the tiles of the farm.

Output Format
An integer — number of minimum moves or -1.

Constraints
1
≤
n
,
m
≤
1000
Grid only contains ., #, M, A
There exists exactly one A in the grid.
Sample Input 1 
4 4
####
..A#
#.##
#M##
Sample Output 1 
2*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> farm(n, vector<char>(m));
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> farm[i][j];
            if (farm[i][j] == 'A') {
                start = {i, j};
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            cout << dist[i][j] << endl;
            return 0;
        }
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if (abs(k) + abs(l) == 1) {
                    int ni = i + k;
                    int nj = j + l;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && farm[ni][nj] != '#' && dist[ni][nj] == -1) {
                        dist[ni][nj] = dist[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
