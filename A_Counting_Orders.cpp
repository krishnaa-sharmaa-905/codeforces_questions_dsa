#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    for(ll i = 0; i<n; i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    vector<int> temp(n);
    sort(b.begin(),b.end());
    ll ind = 0;
    ll cnt  =0;
    for(ll i= 0;i<n;i++){
        ll curra = a[i];
        
        while(ind<n && b[ind]<curra){
            ind++;
            cnt++;
        }
        temp[i]=cnt-i;
    }
    // cout<<"test->temp  ->  ";
    ll ans = 1;
    for(ll i = 0; i<n; i++){
        ans = (ans*temp[i])%1000000007;
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