#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    vector<int> front;
    vector<int> back;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            sum++;
            front.push_back(i + 1);      // position from front
            back.push_back(n - i);       // position from back
        }
    }

    if (sum < s) {
        cout << -1 << endl;
        return;
    }

    int remove = sum - s;
    if (remove == 0) {
        cout << 0 << endl;
        return;
    }

    int ans = INT_MAX;

    // try removing k from front, (remove-k) from back
    for (int k = 0; k <= remove; k++) {
        int fc = 0, bc = 0;

        if (k > 0)
            fc = front[k - 1];

        if (remove - k > 0)
            bc = back[sum - (remove - k)];

        ans = min(ans, fc + bc);
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
