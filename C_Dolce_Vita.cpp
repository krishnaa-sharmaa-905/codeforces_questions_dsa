#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    long long iniSum = accumulate(a.begin(), a.end(), 0LL);
    long long prev = -1, ans = 0;

    for (int i = n; i > 0; i--) {
        long long curr;
        if (k >= iniSum)
            curr = (k - iniSum) / i;
        else
            curr = -1;

        ans += 1LL * i * (curr - prev);
        prev = curr;
        iniSum -= a[i - 1];
    }

    cout << ans << "\n";
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