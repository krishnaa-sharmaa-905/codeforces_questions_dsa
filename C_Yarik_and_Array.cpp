#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;



void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    ll sum = a[0];
    ll ans = a[0];
    ll minsum = min(0, a[0]);

    for (int i = 1; i < n; i++) {
        if ((abs(a[i])%2)==(abs(a[i-1])%2)) {
            sum=0;
            minsum=0;
        }
        sum+=a[i];
        ans=max(ans, sum-minsum);
        minsum = min(minsum, sum);
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