#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second

ll n;
ll ans;
vector<vector<ll>> dp;

// ll help(ll i, ll prev, vll& a, vll& b){
//     if(i>=n){
//         // ans = max(ans,sum);
//         return 0;
//     }
//     if(dp[i][prev]!=-1) return dp[i][prev];

//     ll ans = 0;
//     if(prev==1){
//         //pick or not pick from 2
//         //pick
//         ans = max(b[i] + help(i+1,2, a,b),help(i+1,0,a,b));
//     }

//     else if(prev==2){
//         ans = max(a[i] + help(i+1,1,a,b),help(i+1,0,a,b));
//     }

//     else{
//         ans = max(a[i] + help(i+1,1,a,b), b[i] + help(i+1,2,a,b));
//     }
//     return dp[i][prev] = ans;
// }

void solve() {
    cin>>n;
    vll a(n),b(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    for(ll i = 0; i<n; i++) cin>>b[i];
    ans = 0;
    dp.assign(n+1,vector<ll>(3,-1));

    dp[n][0] = 0;
    dp[n][1] = 0;
    dp[n][2] = 0;

    for(int i = n-1;i>=0;i--){
        dp[i][1] = 1LL*max(b[i] + dp[i+1][2], dp[i+1][0]);

        dp[i][2] = 1LL*max(a[i] + dp[i+1][1], dp[i+1][0]);

        dp[i][0] = 1LL*max(b[i] + dp[i+1][2], a[i] + dp[i+1][1]);
    }

    // ans = help(0,0,a,b);
    ll ans = 1LL*max(dp[0][0], max(dp[0][1], dp[0][2]));
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}