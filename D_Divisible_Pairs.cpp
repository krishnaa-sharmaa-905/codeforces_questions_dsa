#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0;

    map<pair<int,int>, long long> freq;

    for(int i = 0; i < n; i++) {
        int rx = a[i] % x;
        int ry = a[i] % y;
        int needx = (x - rx) % x;
        ans += freq[{needx, ry}];
        freq[{rx, ry}]++;
    }

    cout << ans << endl;
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