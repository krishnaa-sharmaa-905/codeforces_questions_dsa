#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> ans(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    for(ll i = 0;i<n;i++){
        ll big = 0;
        ll small = 0;
        for(ll j = i+1;j<n;j++){
            if(a[j]>a[i]) big++;
            if(a[j]<a[i]) small++;
        }
        ans[i] = max(big,small);
    }
    for(ll i = 0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
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