#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;


void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n), b(n);
    for(ll i = 0; i<n; i++)cin>>a[i];
    for(ll i = 0; i<n; i++)cin>>b[i];
    vector<vector<ll>> query(q,vector<ll>(2));
    for(ll i = 0; i<q; i++){
        cin>>query[i][0]>>query[i][1];
    }
    for(ll i = 0;i<n;i++){
        a[i] = max(a[i],b[i]);
    }
    for(ll i = n-2; i>=0; i--){
        a[i] = max(a[i],a[i+1]);
    }
    vector<ll> sum(n,0);
    sum[0] = a[0];

    for(ll i = 1; i<n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    for(ll i = 0; i<q; i++){
        ll ans = 0;
        ll l = query[i][0]-1;
        ll r = query[i][1]-1;
        if(l==0){
            ans=  sum[r];
        } 
        else{
            ans = sum[r] - sum[l-1];
        }
        cout<<ans<<" ";
    }
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