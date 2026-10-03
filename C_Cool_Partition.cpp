#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mpp1;
    unordered_map<int, int> mpp2;

    int ans = 1;
    int start = 0;
    bool dup = false;
    mpp1[a[0]]++;
    for (int i = 1; i < n; i++) {
        
        if (mpp1.find(a[i]) != mpp1.end()) {
            
            mpp1.erase(a[i]);
            
        }
        if(mpp2.find(a[i])==mpp2.end()){
            mpp2[a[i]]++;
        }
        

        if (mpp1.size() == 0) {
            ans++;
            mpp1.swap(mpp2);
        }
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