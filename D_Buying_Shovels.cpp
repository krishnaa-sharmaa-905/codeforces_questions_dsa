#include <iostream>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(k>=n) {
        cout<<"1"<<endl;
        return;
    }
    int ans= INT_MAX;
    for(int i = 1;i*i<=n;i++){
        if(i>k) break;
        if(n%i == 0){
            ans = min(ans,n/i);
            if(n/i<=k){
                ans = min(ans,i);
            }
        }
        
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