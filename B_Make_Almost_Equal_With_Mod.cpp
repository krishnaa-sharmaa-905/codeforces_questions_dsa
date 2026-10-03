#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;


void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    ll ans = 1;
    for(ll i = 0;i<=60;i++){
        ll num = (ll)pow(2,i);
        set<ll> st;
        for(ll j =  0;j<n;j++){
            ll mod = a[j]%num;
            if(st.find(mod)==st.end()){
                st.insert(mod);
            }
            if(st.size()>2) break;
        }
        if(st.size()==2){
            ans = num;
            break;
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