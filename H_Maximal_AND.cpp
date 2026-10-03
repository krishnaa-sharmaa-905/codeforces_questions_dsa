#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    vector<ll> clr(31),set(31);
    for(ll i = 0;i<n;i++){
        ll num = a[i];
        for(ll j = 0;j<31;j++){
            ll mask = 1<<j;
            if((mask&num) == mask){
                set[j]++;
            }
            else{
                clr[j]++;
            }
        }
    }
    ll ans = 0;
    for(ll i = 30;i>=0;i--){
        if(clr[i]<=k){
            k -= clr[i];
            set[i] += clr[i];
        }
        if(set[i]==n){
            ans += 1<<i;
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