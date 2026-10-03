#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k,b,s;
    cin>>n>>k>>b>>s;
    vector<ll> ans(n);
    ans[0]= k*b;
    s = s-k*b;
    if(s<0){
        cout<<"-1"<<endl;
        return;
    }
    
        for(ll i = 0; i<n; i++){
            ll curr = min(k-1,s);
            ans[i] = ans[i]+curr;
            s = s-curr;
            
        }
        if(s>0){
            cout<<"-1"<<endl;
        }
        else{
            for(ll i = 0; i<n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
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