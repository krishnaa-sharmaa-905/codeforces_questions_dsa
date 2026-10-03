#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    ll x;
    cin >> x;

    for (ll i = 1; i < x; i = i*2) {  
        ll y = x - i;  
        ll z = x ^ y;  

        if ((x+y>z) && (x+z>y) && (z+y>x)) {
            cout<<y<<endl;
            return;
        }
    }

    cout << "-1"<<endl;  
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
