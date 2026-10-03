#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll calcWater(vector<ll> num,ll h){
    ll ans = 0;
    ll n = num.size();
    for(ll i = 0; i<n; i++){
        if(h>num[i]){
            ans+= h-num[i];
        }
    }
    return ans;
}

void solve() {
    ll n,x;
    cin>>n>>x;
    ll maxi = 0;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        maxi = max(a[i],maxi);
    }
    ll s = 1;
    ll e = maxi+x;
    while(s<=e){
        ll m = s +(e-s)/2;
        ll water = calcWater(a,m);
        if(water==x){
            cout<<m<<endl;
            return;
        }
        if(water<=x){
            s=m+1;
        }
        else {
            e=m-1;
        }
    }
    cout<<e<<endl;
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