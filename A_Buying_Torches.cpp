#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    ll x,y,k;
    cin>>x>>y>>k;
    ll b = k;
    ll a = ((k*y)+k-1)/(x-1);
    if((((k*y)+k-1)%(x-1))!=0){
        a++;
    }
    ll ans = a+b;
    cout<<ans<<endl;
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