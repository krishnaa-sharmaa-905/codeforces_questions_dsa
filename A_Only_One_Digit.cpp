#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s = to_string(n);
    int sz = s.size();
    int ans = 9;
    for(int i = 0;i<sz;i++){
        ans = min(ans,s[i]-'0'); 
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