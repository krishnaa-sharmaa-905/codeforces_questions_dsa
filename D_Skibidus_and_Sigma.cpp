#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

typedef long long ll;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> nums(n, vector<int>(m));
    vector<pair<ll, int>> maxsum(n);

    for (int i = 0; i < n; i++) {
        ll currsum = 0;
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
            currsum += nums[i][j];
        }
        maxsum[i] = {currsum, i}; 
    }

    sort(maxsum.rbegin(), maxsum.rend());

    vector<int> concatenated;
    
    for (auto [_, index] : maxsum) {
        concatenated.insert(concatenated.end(), nums[index].begin(), nums[index].end());       
    }

    ll maxScore = 0, prefixSum = 0;
    for (int num : concatenated) {
        prefixSum += num;
        maxScore += prefixSum;
    }

    cout << maxScore << endl;
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
