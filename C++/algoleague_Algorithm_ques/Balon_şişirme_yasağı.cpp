/*At Winter Camp, there is a rule prohibiting students from making noise after midnight. Those who violate this rule are subjected to a penalty of inflating balloons. It is required to inflate balloons for use in the Final Contest of the camp. While inflating balloons, students are trying to predict different sums they can obtain from the balloons in their hands.


For example, if the balloon capacities are 
4
, 
2
, 
6
, and 
10
, and a student makes a prediction of 
16
, they are considered to have made a correct prediction because they can achieve the capacity of 
16
 by inflating the 
3
r
d
 and 
4
t
h
 balloons. However, if a student predicts 
13
 as the capacity, it is considered a wrong prediction since there is no way to achieve this capacity.
There are a total of 
n
 balloons and 
m
 students. Each student makes one prediction. You are asked to determine which students' predictions are correct based on the given balloons' capacities and students' predictions. You need to output yes for those who made correct predictions and no for those who made incorrect predictions.

Input Format
The first line includes 
n
, 
m
 — number of balloons and number of students.

The second line includes 
b
a
l
l
o
o
n
s
1
,
b
a
l
l
o
o
n
s
2
,
…
,
b
a
l
l
o
o
n
s
n
 — the capacities of the balloons.

The third line includes 
p
r
e
d
i
c
t
i
o
n
s
1
,
p
r
e
d
i
c
t
i
o
n
s
2
,
…
,
p
r
e
d
i
c
t
i
o
n
s
n
 — students' predictions.

Output Format
For the 
i
t
h
 line, yes indicates that the 
i
t
h
 student's prediction is correct, and no indicates that the 
i
t
h
 student's prediction is incorrect.

Constraints
1
≤
n
≤
500
1
≤
m
≤
2
⋅
10
5
1
≤
b
a
l
l
o
o
n
s
i
≤
100
1
≤
p
r
e
d
i
c
t
i
o
n
s
i
≤
5
⋅
10
4
Sample Input 1 
4 2
4 2 6 10
16 13
Sample Output 1 
yes
no*/


//https://algoleague.com/problem/balon-sisirme-yasagi/detail


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//using dynamic programming 

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>balloons(n);
    vector<int>predictions(m);
    for(int i=0;i<n;i++){
        cin>>balloons[i];
    }
    for(int i=0;i<m;i++){
        cin>>predictions[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(50001,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=50000;j++){
            if(j>=balloons[i-1]){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-balloons[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<m;i++){
        if(predictions[i]<=50000 && dp[n][predictions[i]]){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    
    



    return 0;
}