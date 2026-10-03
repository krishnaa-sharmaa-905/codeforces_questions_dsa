#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    string t;
    cin>>t;
    t = "0" + t;
    // cout<<t<<endl;
    vector<bool> removed(n+1,false);
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j+=i){
            if(t[j]=='1'){
                break;
            }
            else{
                if(removed[j]==true){
                    continue;
                }
                else{
                    removed[j] = true;
                    ans += i;
                }
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