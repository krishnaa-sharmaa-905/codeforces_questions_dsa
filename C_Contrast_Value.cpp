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
    for(int i = 0; i<n; i++)cin>>a[i];
    vector<int> temp;
    n = unique(a.begin(), a.end()) - a.begin();
    int ans = n;
    for(int i = 0;i + 2<n;i++){
        if((a[i]<a[i+1] && a[i+1]<a[i+2]) || (a[i]>a[i+1] && a[i+1]>a[i+2])){
            ans--;
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