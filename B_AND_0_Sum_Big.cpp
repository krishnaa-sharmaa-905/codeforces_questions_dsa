#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    ll ans = 1;

    while(k--){
        ans = (n*ans)%1000000007;
    }
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