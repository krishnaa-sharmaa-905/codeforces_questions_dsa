#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin>>s;
    ll n = s.size();
    ll cntv = 0;
    vector<ll> fwd,back;
    for(ll i = 0;i<n;i++){
        if(s[i]=='v'){
            cntv++;
        }
        else{
            ll temp = 0;
            if(fwd.size()>=1){
                temp = fwd.back();
            }
            if(cntv>=2){
                fwd.push_back(cntv-1 + temp);
            }
            else{
                fwd.push_back(temp);
            }
            cntv = 0;
        }
    }
    cntv = 0;
    for(ll i = n-1;i>=0;i--){
        if(s[i]=='v'){
            cntv++;
        }
        else{
            ll temp = 0;
            if(back.size()>=1){
                temp = back.back();
            }
            if(cntv>=2){
                back.push_back(cntv-1 + temp);
            }
            else{
                back.push_back(temp);
            }
            cntv = 0;
        }
    }
    ll ans= 0;
    reverse(back.begin(), back.end());
    // cout<<fwd.size()<<" "<<back.size()<<endl;
    for(ll i = 0;i<back.size();i++){
        // cout<<fwd[i]<<" "<<back[i]<<endl;
        ans += fwd[i]*back[i];
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}