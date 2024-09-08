/*
Işıl loves playing CS:GO with her friends, but she hates when they only want to play Dust 2. She believes other maps are just as good, but her friends insist that 2,000 hours on Dust 2 still isn’t enough. So, Işıl comes up with a plan: she’s going to build a new map that her friends will love, just to get them off Dust 2.

So she creates 
N
 areas and marks them as T or CT areas. Then she connects these areas and builds connections with integer similarity value 
x
i
. The similarity value represents how similar each connection is to Dust 2.

Seeing that this map is a complete mess, Işıl decides to make some alterations.

She doesn't want any unnecessary connections between areas, so she decides to delete the excess connections and aims to minimize the sum of the remaining connections' similarity values while ensuring every area is reachable from every other area. Lastly, after fulfilling all other requirements, she wants to use as few connections as possible between CT and T areas.

What is the minimum number of remaining connections between CT and T areas while still meeting Işıl's requirements?

If Işıl's requirements can't be met, print 
−
1
.

Input Format
First line contains 
N
 and 
M
, number of areas and number of connections, respectively.
Second line contains 
N
 strings T or CT.
Next M line contains 
3
 integers, 
s
i
, 
d
i
 and 
x
i
 denoting connection between 
s
i
 and 
d
i
 with similarity value 
x
i
.
Output Format
Print the minimum number of remaining connections between CT and T areas while still meeting Işıl's requirements. If Işıl's requirements can't be met, print 
−
1
.

Constraints
1
≤
N
≤
2
⋅
10
5
1
≤
M
≤
4
⋅
10
5
1
≤
s
i
,
d
i
≤
N
s
i
≠
d
i
1
≤
x
i
≤
10
9
Sample Input 1 
4 5
CT T T CT 
3 2 1
2 4 2
3 4 2
2 1 2
3 1 1
Sample Output 1 
2
Explanation 1
Edges 
(
3
,
1
)
,
(
3
,
2
)
 and 
(
3
,
4
)
 are chosen to minimize the sum of the remaining connections' similarity values, which is 
4
, while ensuring every area is reachable from every other area.

Edges 
(
3
,
1
)
 and 
(
3
,
4
)
 have connections between T and CT, so the answer is 
2
.

Sample Input 2 
4 6
CT T T CT 
4 3 1
3 1 1
2 1 1
4 2 1
1 4 1
2 3 1
Sample Output 2 
1
Explanation 2
Edges 
(
1
,
4
)
, 
(
2
,
3
)
, and 
(
1
,
2
)
 are chosen to minimize the sum of the remaining connections' similarity values, which is 
3
, while ensuring every area is reachable from every other area and using as few connections as possible between CT and T areas.

Only the edge 
(
1
,
2
)
 has a connection between T and CT, so the answer is 
1
.

Sample Input 3 
10 7
CT CT T CT CT CT T CT T T 
9 3 5
4 2 3
6 10 2
7 9 1
4 5 2
7 6 1
6 5 5
Sample Output 3 
-1
Explanation 3
It is impossible to meet Işıl's requirement of ensuring every area is reachable from every other area.*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> areas(n);
    for (int i = 0; i < n; i++) {
        cin >> areas[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }
    vector<vector<int>> dist(n, vector<int>(2, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto [d, p] = pq.top();
        pq.pop();
        int u = p.first;
        int t = p.second;
        if (d > dist[u][t]) {
            continue;
        }
        for (auto [v, x] : adj[u]) {
            if (dist[v][t ^ 1] > dist[u][t] + x) {
                dist[v][t ^ 1] = dist[u][t] + x;
                pq.push({dist[v][t ^ 1], {v, t ^ 1}});
            }
        }
    }
    if (dist[n - 1][1] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dist[n - 1][1] << endl;
    }
    return 0;
}
