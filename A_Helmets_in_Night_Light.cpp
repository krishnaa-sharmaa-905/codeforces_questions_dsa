#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

void solve(){
    ll n,p;
    cin>>n>>p;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<pair<ll,ll>> use(n);
    // agar aadmi ki cost jyada hai information pass karne ki toh fir chief karega
    for(ll i = 0; i<n; i++){
        ll cost;
        cin>>cost;
        ll min_cost = min(p,cost);
        use[i].first = min_cost;
        use[i].second = a[i];
    }
    sort(use.begin(),use.end());
    ll ans= p;
    ll rem = n-1;
    for(ll i = 0; i<n-1; i++){
        ll spread = min(use[i].second,rem);
        ans += spread*use[i].first;
        rem -= spread;
    }
    cout<<ans<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}