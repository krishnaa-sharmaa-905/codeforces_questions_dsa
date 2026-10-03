#include <iostream>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int ans = 2*n-3;
    cout<<ans<<endl;
// 1based 
// reverse from back
    for(int i = 2;i<=n;i++){
        cout<<i<<" "<<n+1-i<<" "<<n<<endl;
    }
    // reverse from front top n-2 rows
    for(int i = 1;i<=n-2;i++){
        cout<<i<<" "<<1<<" "<<n-i<<endl;
    }

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