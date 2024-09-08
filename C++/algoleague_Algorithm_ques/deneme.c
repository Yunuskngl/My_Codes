/*During the upsolving day at summer camp, the activities were so enjoyable. Thus, participants wanted to attend everything. But at the end of the day, they became so tired, especially Gamze. She wanted to solve this problem. She wrote each activity and assigned numbers to them, from 
1
 to 
n
. Starting from activity number 
i
, 
(
1
≤
i
≤
n
)
, she'll pick her next activity 
j
 and it can be either 
i
+
1
 or 
i
+
2
. Each activity has a happiness point 
=
a
i
. The change between two activities is tiring, each activity change has an effort equal to the absolute value of happiness difference between the two activities 
(
|
a
i
−
a
j
|
)
. Find out the minimum overall effort.

You can access the editorial for this question by clicking on this Editorial link.

Input Format
First line, 
n
, number of activities.

Second line, 
n
 numbers, happiness values of all activities from morning till night.

Output Format
1 integer - minimum effort to finish the day starting from 
a
c
t
i
v
i
t
y
1
 and ending at 
a
c
t
i
v
i
t
y
n
.

Constraints
1
≤
n
≤
10
5
1
≤
a
i
≤
10
5
 
∀
 
1
≤
i
≤
n
Sample Input 1 
2
1 10
Sample Output 1 
9
Sample Input 2 
7
2 1 4 3 4 12 11
Sample Output 2 
9
Explanation 2
The optimal path is: 2 -> 4 -> 4 -> 11 which costs 2 + 0 + 7 = 9


c kodu yaz
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *dp = (int *)malloc(n * sizeof(int));
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = abs(arr[i] - arr[i - 1]) + dp[i - 1];
        if (i > 2)
        {
            dp[i] = dp[i] < abs(arr[i] - arr[i - 2]) + dp[i - 2] ? dp[i] : abs(arr[i] - arr[i - 2]) + dp[i - 2];
        }
    }
    printf("%d", dp[n - 1]);
    return 0;
}

    
