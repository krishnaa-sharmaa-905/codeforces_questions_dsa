#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<ll> presum(n+1);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    presum[0]=0;
    for(int i = 0; i<n; i++){
        presum[i+1] = a[i]+presum[i];

    }
    ll ans = 0;
    for(int i = 0; i<=k; i++){
        ans = max(ans,presum[n-i]-presum[2*(k-i)]);
        
    }
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