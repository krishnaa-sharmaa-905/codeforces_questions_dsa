#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> fr;
    for (ll i = 0; i < n; i++) fr[a[i]]++;

    vector<ll> odd;
    ll ans = 0, cnt = 0;
    for (auto x : fr) {
        if (x.second & 1) odd.push_back(x.first);
        ans += (x.second / 2) * 2 * x.first;
        cnt += (x.second / 2) * 2;
    }

    if (ans == 0) {
        cout << 0 << "\n";
        return;
    }

    sort(odd.begin(), odd.end());
    ll maxi = 0;

    for (ll i = 0; i < odd.size(); i++) {
        if (odd[i] < ans) {
            maxi = max(maxi, ans + odd[i]);
        }
    }

    for (ll i = 1; i < odd.size(); i++) {
        if (odd[i] - odd[i - 1] < ans) {
            maxi = max(maxi, ans + odd[i] + odd[i - 1]);
        }
    }

    if (cnt > 2) {
        maxi = max(maxi, ans);
    }

    cout << maxi << "\n";
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