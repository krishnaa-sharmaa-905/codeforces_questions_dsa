#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int r= n-1;
    int ans = 0;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        count++; 
        if (count * a[i] >= x) {
            ans++; 
            count = 0; 
        }
    }
    cout<<ans<<endl;
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