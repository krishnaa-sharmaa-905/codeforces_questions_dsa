#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,d;
    cin>>n>>m>>d;
    int x = d/m +1;
    cout<<(n+x-1)/x<<endl;
    string s = "2374236843276813";
    // sort(s.begin(),s.end());
    // if(m==1) cout<<s.size()<<" "<<s<<endl;
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
