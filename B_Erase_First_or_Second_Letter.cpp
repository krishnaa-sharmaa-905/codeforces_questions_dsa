#include <iostream>
#include <string>
#include<set>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char> b;
    int ans = 0;
    for(int i = 0; i<n; i++){
        b.insert(s[i]);
        ans += b.size();
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