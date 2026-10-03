#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    int lans = 0;
    int rans = 0;
    rans = min(r,m);
    m = rans-m;
    lans = m;
    cout<<lans;
    cout<<" "<<rans<<endl;
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