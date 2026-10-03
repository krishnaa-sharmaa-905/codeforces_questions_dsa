#include <iostream>
#include <vector>
using namespace std;

bool canMake(int x, int k, const vector<int>& a) {
    vector<bool> seen(x, false);
    int count = 0, found = 0;

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < x && !seen[a[i]]) {
            seen[a[i]] = true;
            found++;
        }

        if (found == x) {
            count++;
            seen.assign(x, false); // reset all to false
            found = 0;
        }
    }

    return count >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canMake(mid, k, a)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
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
