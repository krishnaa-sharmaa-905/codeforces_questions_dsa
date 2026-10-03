#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007LL;

vector<vector<ll>> generate(ll n) {
   vector<vector<ll>> ans;
   ans.push_back({1});
   for(ll row = 1;row<=n;row++){
    vector<ll> temp(row+1);
    for(ll i = 0;i<=row;i++){
        if(i==0 || i==row){
            temp[i] = 1;
        }
        else{
            temp[i] = ans[row-1][i]+  ans[row-1][i-1];
        }
    }
    ans.push_back(temp);
   }
   return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> ncj = generate(n+1);
    ll ans = 0;
    for(ll i = 1;i<=n;i++){
        if(i%2==1) continue;
        ll ones = (i-1)/2;
        ll zeroes = i/2;
        ans += (ncj[ones+zeroes][ones]%MOD);
        ans= ans%MOD;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}