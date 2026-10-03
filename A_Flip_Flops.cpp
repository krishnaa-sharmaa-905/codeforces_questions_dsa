#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll> a(n);
    for(ll i =0 ;i<n;i++ ) cin>>a[i];
    sort(a.begin(),a.end());
    for(ll i = 0; i<n; i++){
        if(a[i]>c) break;
        ll drop = c-a[i];
        if(drop>k){
            drop = k;
            k = 0;
        }
        else{
            k-=drop;
        }
        c+= drop + a[i];
    }
    cout<<c<<endl;
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