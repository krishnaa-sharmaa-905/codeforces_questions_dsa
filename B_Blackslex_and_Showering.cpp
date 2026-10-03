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
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    ll sum = 0;
    for(int i = 0;i<n-1;i++){
        sum += abs(a[i]-a[i+1]);
    }

    ll ans = LLONG_MAX;
    ans = min(sum,sum- abs(a[0]-a[1]));//remove first
    ans = min(ans, sum-abs(a[n-1]-a[n-2]));

    for(int i = 1;i<n-1;i++){
        ll temp = sum - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]);
        ans = min(ans, temp);
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