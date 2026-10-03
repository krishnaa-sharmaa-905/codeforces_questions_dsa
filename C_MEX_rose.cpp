#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), freq(k);
    int cntk = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == k) cntk++;
        if(a[i] < k) freq[a[i]]++;
    }

    int miss = 0;
    for(int i = 0; i < k; i++) {
        if(!freq[i]) miss++;
    }

    cout << max(miss, cntk) << "\n";
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