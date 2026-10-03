#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;



void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    vector<ll> sum(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i].first ;
        a[i].second = i;

    }
    sort(a.begin(),a.end());
    sum[0] = a[0].first;
    for(ll i = 1; i<n; i++){
        sum[i] = sum[i-1]+a[i].first;
    }

    vector<ll> temp(n);
    temp[n-1] = n-1;
    for(ll i = n-2; i>=0; i--){
        
       if(sum[i]>=a[i+1].first){
            temp[i] = temp[i+1];
       }
       else{
        temp[i] = i;
       }
    }
    vector<ll> ans(n);
    for(int i = 0; i<n; i++){
        ans[a[i].second] = temp[i];
    }
    
    for(ll i = 0; i<n; i++){

        cout<<ans[i]<<" ";
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