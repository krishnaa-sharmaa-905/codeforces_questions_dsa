#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n+2);
    a[0] = 0;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1] = x;
    int ans = 0;
    for(int i= 0;i<n+1;i++){
        ans = max(ans,a[i+1]-a[i]);
    }
    ans = max(ans,2*(a[n+1]-a[n]));
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
// 1010
// 11010
//11010
// 00000101
// jo extra hai use pehle likh lo 
// jo kam hai use baad mein likho