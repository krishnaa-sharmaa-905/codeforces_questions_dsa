#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
   ll n,a,b;
   cin>>n>>a>>b;
    ll ans = 0;
   ll groups = n / 3;
    ll rem = n % 3;

    ans = groups * min(b, 3 * a);
    ans += min(b, rem * a);

    cout << ans << endl;

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