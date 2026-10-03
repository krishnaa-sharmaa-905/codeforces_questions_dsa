#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    map<ll,ll> mpp;

    for(ll i = 0;i<n;i++){
        for(ll j = 31;j>=0;j--){
            ll mask = 1<<j;
            if((mask & a[i]) == mask){
                if(mpp.find(j)!=mpp.end()){
                    mpp[j]++;
                }
                else{
                    mpp[j] = 1;
                }
                break;
            }
        }
    }
    ll ans = 0;
    for(auto it:mpp){
        ll cnt = it.second;
        if(cnt>1){
            if(cnt%2==0){
                ans += ((cnt/2) *(cnt-1)); 
            }
            else{
                ans += (((cnt-1)/2) *(cnt)); 
            }
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