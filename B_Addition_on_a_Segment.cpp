#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    for(ll i = 0; i<n; i++) cin>>a[i];
    ll nonzero = 0;
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        sum += a[i];
        if(a[i]>0) nonzero++;
    }
    ll afterop1 = sum - nonzero;
    ll rem = n-1-afterop1;
    ll ans = nonzero-max(1LL*0,rem);
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}