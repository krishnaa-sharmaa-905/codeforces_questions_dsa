#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> pre(n), suff(n), res(n);

        pre[0] = a[0], suff[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = max(a[i], pre[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(a[i], suff[i + 1]);
        }

        res[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            res[i] = pre[i];
            if (pre[i] > suff[i + 1]) {
                res[i] = res[i + 1];
            }
        }
        for( int x : res) cout << x << " ";
        cout << "\n";
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