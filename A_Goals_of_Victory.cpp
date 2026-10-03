#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0; i<n-1; i++){
        cin>>a[i];
        ans += a[i];
    }
    cout<<ans*-1<<endl;
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