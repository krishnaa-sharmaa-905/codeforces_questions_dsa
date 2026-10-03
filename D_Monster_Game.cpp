#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(ll i = 0; i<n; i++)cin>>a[i];
    for(ll i = 0; i<n; i++)cin>>b[i];
    sort(a.begin(),a.end());
    unordered_map<ll,ll> mpp;
    ll ans = 0;
    vector<ll> sum(n);
    sum[0] = b[0];
    for(ll i = 1;i<n;i++){
        sum[i] = sum[i-1] + b[i];
    }
    for(ll i=  0;i<n;i++){
        if(mpp.find(a[i])!=mpp.end()){
            continue;
        }
        else{
            mpp[a[i]] = 1;
            ll swordcnt = n-i;
            ll diffi = a[i];
            ll level = upper_bound(sum.begin(), sum.end(), swordcnt) - sum.begin();
            ans = max(ans,diffi*level);
        }
    }
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}