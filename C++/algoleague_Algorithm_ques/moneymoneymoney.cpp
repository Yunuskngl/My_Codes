/*Anıl and Berke are very good friends. One day, Berke goes to Anıl and asks for investment advice. But before asking for advice, he made some decisions about his investments. He filtered the best 
n
 stocks from the stock market. Berke will invest at most 
m
 stocks among these 
n
 stocks. And if he is going to invest in a stock he can only invest 1 unit. With these decisions he goes to Anıl. Of course there is a reason why he goes to Anıl, he is very good in Artificial Intelligence, he can make the best analysis about stocks 😎🤌.

Anıl runs some Machine Learning algorithms and comes up with results about stocks. He finds each stock's return value. (
s
i
 represents the return value of the 
i
t
h
 stock). He also comes up with a 
c
 number of constraints to Berke because Berke wants a risky portfolio with high returns. Each constraint 
i
 contains two stocks: 
c
i
0
 and 
c
i
1
. It means that these stocks have a similar profile and if Berke invests in 
c
i
0
 he should also invest in 
c
i
1
.

Berke loves Anıl's advice and then he writes a code with him in order to find maximum return value while listening Money, Money, Money. Can you also write the code for finding maximum return value 🤑?

Input Format
First line contains three space separated integers: 
n
, 
m
 and 
c
. Number of stocks determined by Berke, upper bound of Berke's investments and number of constraints determined by Anıl, respectively.
Second line contains 
n
 space separated integers which are return values of each stock.
Next 
c
 lines contain 
2
 space separated integers which are 
c
i
0
 and 
c
i
1
.
Output Format
Maximum return value which fits every constraint given above.
Constraints
1
≤
n
≤
20
1
≤
m
≤
n
0
≤
c
≤
n
2
0
≤
s
i
≤
10
6
0
≤
c
i
0
,
c
i
1
<
n
Each stock is in at most one constraint
Sample Input 1 
3 1 1
12 3 10
0 1
Sample Output 1 
10
Explanation 1
Berke can not invest to 
s
0
 because when he invests into 
s
0
 he must invest into 
s
1
 also. But this violates the maximum number of stocks that can be invested. Therefore he invests into 
s
2
.

Sample Input 2 
3 1 0
12 3 10
Sample Output 2 
12
Explanation 2
Berke can invest into 
s
0
 for maximum return value and then he can buy chocolate to Anıl 😌.*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define MAX 1000005
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define F first
#define S second
#define MAXN 1000005
#define INF 1e18
#define EPSILON 1e-9
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug4(w, x, y, z) cout << #w << " = " << w << ", " << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug_arr(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl
#define debug_arr2(a, n, m) for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) cout << a[i][j] << " "; cout << endl; }
#define debug_pii(p) cout << #p << " = " << p.F << ", " << p.S << endl
#define debug_vii(v) for(auto x : v) cout << x.F << " " << x.S << endl
#define debug_set(s) for(auto x : s) cout << x << " "; cout << endl
#define debug_map(m) for(auto x : m) cout << x.F << " " << x.S << endl

int n, m, c;
vi stocks;
vector<vi> constraints;
int ans = 0;

void solve(int idx, int cnt, int sum) {
    if(cnt == m) {
        ans = max(ans, sum);
        return;
    }
    if(idx == n) {
        return;
    }
    bool flag = false;
    for(int i = 0; i < c; i++) {
        if(constraints[i][0] == idx) {
            flag = true;
            if(find(all(constraints[i]), idx) != constraints[i].end()) {
                if(find(all(constraints[i]), idx) == constraints[i].begin()) {
                    solve(idx + 1, cnt + 1, sum + stocks[idx]);
                } else {
                    solve(idx + 1, cnt + 1, sum + stocks[idx]);
                }
            }
        }
    }
    if(!flag) {
        solve(idx + 1, cnt + 1, sum + stocks[idx]);
    }
    solve(idx + 1, cnt, sum);
}

int32_t main() {
    fastio;
    cin >> n >> m >> c;
    stocks.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> stocks[i];
    }
    constraints.resize(c, vi(2));
    for(int i = 0; i < c; i++) {
        cin >> constraints[i][0] >> constraints[i][1];
    }
    solve(0, 0, 0);
    cout << ans << endl;
    return 0;
}
