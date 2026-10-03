#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    if(k>=3){
        cout<<"0"<<endl;
        return;
    }

    vector<ll> diff;
    ll ans = a[0];
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll d = a[j] - a[i];
            diff.push_back(d);
            ans = min(ans, d);
        }
    }
    if(k==1){
        cout<<ans<<endl;
        return;
    }
    for(ll i = 0;i<diff.size();i++){
        ll index = lower_bound(a.begin() ,a.end() ,diff[i]) - a.begin();
        if(index>=1 && index<=n-1){
            ans = min(ans,abs(diff[i] - a[index]));
            ans = min(ans,abs(diff[i]-a[index-1]));
        }
        else if(index==0){
            ans = min(ans,abs(diff[i] - a[index]));
        }
        else{
            ans = min(ans,abs(diff[i]-a[n-1]));
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