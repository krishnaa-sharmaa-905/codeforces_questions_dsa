#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);         
    vector<ll> pref(n + 1);  
    vector<ll> prefmax(n);   

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];

        if (i == 0) prefmax[i] = a[i];
        else prefmax[i] = max(prefmax[i - 1], a[i]);
    }

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;

        
        int idx = upper_bound(prefmax.begin(), prefmax.end(), k) - prefmax.begin();

        cout << pref[idx] << " ";
    }
    cout << endl;
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
