#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> s(n);
    for(ll i = 0; i<n; i++){
        cin>>s[i];
    }

    vector<ll> ans(n);

    
    for (ll i = 0; i < n; i++) {
        
        ans[i] = i + 1;
    }

    ll l = 0;
    for(ll r = 0;r<n;){
        ll rpt = 0;
        while(s[l]==s[r] && r<n ){
            rpt++;
            r++;
        }
        if(rpt<2){
            cout<<"-1"<<endl;
            return;
        }
        rotate(ans.begin()+l,ans.begin()+r-1,ans.begin()+r);
       
        l=r;
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