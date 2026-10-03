#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;

//copied
 
void solve() {
    int n;
    cin >> n;
 
    int minn = 1e9;
    vector<int> min2;
    for (int i = 0 ; i < n ; i++) {
        int m;
        cin >> m;
        vector<int> v(m);
        for (auto &el : v) cin >> el;
 
        int minel = *min_element(v.begin(), v.end());
        minn = min(minn, minel);
        v.erase(find(v.begin(), v.end(), minel));
        min2.push_back(*min_element(v.begin(), v.end()));
    }
    cout << minn + (ll) accumulate(min2.begin(), min2.end(), 0ll) - *min_element(min2.begin(), min2.end()) << "\n";
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