#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,x,y;
    cin>>n>>x>>y;
    ll nx = n/x;
    ll ny = n/y;

    ll common = n/lcm(x,y);

    ll ex= nx-common;
    ll ey = ny - common;

    ll sumx = ex*(2*n - ex + 1);
    sumx = sumx/2;

    ll sumy = ey*( ey + 1);
    sumy = sumy/2;

    ll ans = sumx-sumy;
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