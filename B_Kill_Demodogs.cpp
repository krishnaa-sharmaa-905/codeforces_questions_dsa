#include <iostream>
using namespace std;
typedef long long ll;
const int n1 = 1e9+7;

void solve() {
    ll n;
    cin>>n;
    ll ans = ((((n*(n+1))%n1)*(4*n-1))%n1*337)%n1;
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