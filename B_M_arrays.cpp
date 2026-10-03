#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x % m]++;
    }

    int ans = 0;

    if (freq.count(0)) {
        ans++;
        freq.erase(0);
    }

    for (int r = 1; r <= m / 2; r++) {
        if (r == m - r) {
            if (freq.count(r)) {
                ans++;
            }
        } else {
            int left = freq.count(r) ? freq[r] : 0;
            int right = freq.count(m - r) ? freq[m - r] : 0;

            if (left == 0 && right == 0) continue;

            ans++;
            int extra = abs(left - right) - 1;
            if (extra > 0) ans += extra;
        }

        freq.erase(r);
        freq.erase(m - r);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
