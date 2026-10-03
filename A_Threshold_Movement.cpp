#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    vector<int> w(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    if (n & 1) {
        cout << "NO\n";
        return;
    }

    int maxEven = INT_MIN;
    int minOdd = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (i & 1)
            minOdd = min(minOdd, w[i]);
        else
            maxEven = max(maxEven, w[i]);
    }

    if (maxEven < minOdd)
        cout << "YES\n";
    else
        cout << "NO\n";
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