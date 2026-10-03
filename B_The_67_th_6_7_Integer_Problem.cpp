#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n = 7;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans = 1LL*accumulate(a.begin(),a.end()-1,0*1LL);
    ans = a[6]-ans;
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