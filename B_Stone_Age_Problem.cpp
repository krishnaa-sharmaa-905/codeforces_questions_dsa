#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<vector<ll>> io;
    ll lastall = -1;
    for(ll i = 0;i<q;i++){
        vector<ll> temp;
        ll t;
        cin>>t;
          
        
        if(t==1){
            ll x;
            ll j;
            cin>>j>>x;
            if(lastall==-1){
                sum = sum-a[j-1]+x;
            }
            else{
                sum = sum -lastall+x;
                
            }
            a[j - 1] = x;
            // last = x;

        }
        if(t==2){
            ll x;
            cin>>x;
            sum = 1LL*x*n;
            lastall = x;
            // fill(a.begin(),a.end(),x);
        }
        cout<<sum<<endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        solve();
    
    return 0;
}