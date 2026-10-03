#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vll vector<ll>


void solve() {
    ll n;
    cin>>n;
    vll a(n);
    for(ll i = 0; i<n; i++)cin>>a[i];
    ll sum = 0;
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        if(a[i]%2==1) sum += a[i];
        else ans += sum*a[i];
    }
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}