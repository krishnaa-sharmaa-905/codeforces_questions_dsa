#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int curr = a[k - 1];
    vector<int> height;

    
    for (int i = 0; i < n; i++) {
        if (a[i] >= curr) {
            height.push_back(a[i]);
        }
    }

    
    sort(height.begin(), height.end());

    
    int pos = lower_bound(height.begin(), height.end(), curr) - height.begin();
    bool canReach = true;

    for (int i = pos; i < height.size() - 1; i++) {
        int diff = height[i + 1] - height[i];
        if (diff > curr) {
            canReach = false;
            break;
        }
        curr += diff;
    }

    cout << (canReach ? "YES" : "NO") << '\n';
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