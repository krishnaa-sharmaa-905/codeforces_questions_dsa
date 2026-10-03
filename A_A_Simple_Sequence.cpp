#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    for(int i = n-1; i>=0; i--){
        cout<<i+1<<" ";
    }
    cout<<endl;
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