#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }

    int total_pairs = n / 2;
    int bad_pairs = total_pairs - k;

    if (bad_pairs < 0 || bad_pairs > min(cnt0, cnt1)) {
        cout << "NO" << endl;
        return;
    }

    int remaining0 = cnt0 - bad_pairs;
    int remaining1 = cnt1 - bad_pairs;

    int cnt = (remaining0 / 2) + (remaining1 / 2); // cnt now means max possible good pairs
    if (cnt >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
