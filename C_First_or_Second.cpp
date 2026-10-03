#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<ll> pre(n+1,0);
    for(int i = 1; i<n; i++){
        pre[i+1] = abs(a[i])  + pre[i];
    }
    vector<ll> suf(n,0);
    for(int i = n-1; i>=1; i--){
        suf[i-1] = suf[i] - a[i];
    }
    ll ans = suf[0];
    //i is the not selected child
    for(int i = 1; i<n; i++){
        ans = max(ans,a[0]+pre[i]+suf[i]);    
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