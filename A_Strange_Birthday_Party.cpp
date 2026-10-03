#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> frnd(n), cost(m);
    for(ll i = 0; i<n; i++)cin>>frnd[i];
    for(ll i = 0; i<m; i++)cin>>cost[i];
    sort(frnd.begin(),frnd.end());
    ll ans = 0;
    ll gift= 0;
    for(ll i = n-1; i>=0; i--){
        if(gift<m && cost[frnd[i]-1] >= cost[gift]){
            ans += cost[gift];
            gift++;
        }
        else{
            ans += cost[frnd[i]-1];
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