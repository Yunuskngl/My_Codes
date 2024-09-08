









#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;  // burada her seferinde long long yazmak yerine ll yazarak kısalttık.
int main(){
    ll n;   //aktivite sayısı
    cin>>n;  
    vector<ll>activities(n);  //aktivitelerin mutluluk değerlerini tutacak olan vektör
    for(ll i=0;i<n;i++){
        cin>>activities[i]; 
    }
    vector<ll>dp(n); //dp dizisi oluşturduk bu da her aktivite için minimum mutluluk değerini tutacak.
    dp[0]=0;   //ilk aktiviteyi seçtiğimizde mutluluk değeri 0 olacak.
    dp[1]=abs(activities[1]-activities[0]);    //ikinci aktiviteyi seçtiğimizde ise mutluluk değeri ilk aktivite ile ikinci aktivite arasındaki mutluluk farkı olacak.
    for(ll i=2;i<n;i++){   //3. aktiviteden başlayarak her aktivite için minimum mutluluk değerini hesapladık.
        dp[i]=min(dp[i-1]+abs(activities[i]-activities[i-1]),dp[i-2]+abs(activities[i]-activities[i-2]));  
        //her aktivite için i-1. aktiviteyi seçtiğimizdeki mutluluk değeri ile i-2. aktiviteyi seçtiğimizdeki mutluluk değerini karşılaştırıp minimum olanı seçtik.
    }
    cout<<dp[n-1]<<endl; //en son aktiviteyi seçtiğimizdeki mutluluk değerini yazdırdık.
return 0;}