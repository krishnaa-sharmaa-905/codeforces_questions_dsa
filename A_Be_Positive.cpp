#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0;
    int ans = 0;
    int maxneg= INT_MIN;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]<0){
            neg++;
            maxneg = max(maxneg,a[i]);
        } 
        if(a[i]==0) ans++;
    } 
    if(neg%2!=0){
        ans += abs(maxneg)+1;
    }
    cout << ans << "\n";
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