#include <iostream>
using namespace std;
void solve() {
    int n,x,m;
    cin>>n>>x>>m;
    int i = x;
    int j = x;
    for(int k = 0;k<m;k++){
        int l,r;
        cin>>l>>r;
        if((l<=i && i<=r) || (j<=r && j>=l)){
            i = min(i, l);
            j = max(j, r);

        }
    }
    cout<<j-i+1<<endl;
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