/*Chef Cemil is the renowned chef of the exquisite restaurant Od Urla. Chef Cemil is preparing a special tasting menu that showcases the restaurant's unique dishes. Each dish in the restaurant has two properties: sweetness and sourness.

Chef Cemil wants to create the longest possible tasting menu where the dishes are sorted in non-decreasing order of both sweetness and sourness.

Your task is to help Chef Cemil determine the maximum number of dishes he can include in his tasting menu.

Input Format
The first line of the input contains a single integer 
N
, the number of dishes.

The next 
N
 lines contain two integers 
S
i
 and 
T
i
, the sweetness and sourness of the 
i
-th dish.

Output Format
Output a single integer, the maximum number of dishes Chef Cemil can include in his tasting menu.

Constraints
1
≤
N
≤
10
5
0
≤
S
i
,
T
i
≤
10
9
Sample Input 1 
5
3 3
1 2
2 1
4 4
1 3
Sample Output 1 
4
Explanation 1
Dish 2
Dish 5
Dish 1
Dish 4*/

x
int32_t main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dishes(n);
    for(int i = 0; i < n; i++) {
        cin >> dishes[i].F >> dishes[i].S;
    }
    sort(all(dishes));
    int ans = 1;
    int lastSweetness = dishes[0].F;
    int lastSourness = dishes[0].S;
    for(int i = 1; i < n; i++) {
        if(dishes[i].F >= lastSweetness && dishes[i].S >= lastSourness) {
            ans++;
            lastSweetness = dishes[i].F;
            lastSourness = dishes[i].S;
        }
    }
    cout << ans << endl;
}




