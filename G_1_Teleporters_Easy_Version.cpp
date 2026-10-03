#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        a[i]=a[i]+1+i;
    }
    ll ans = 0;
    sort(a.begin(),a.end());
    for(ll i = 0; i<n; i++){
        // c--;
        if(a[i]==c){
            ans++;
            cout<<ans<<endl;
            return;
        }
        else if(c>a[i]){
            c = c-a[i];//-(i+1);
            ans++;
        }
        else{
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