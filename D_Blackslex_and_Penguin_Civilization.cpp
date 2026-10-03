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
    vector<ll> ans;
    ll num = (1LL << n);
    vector<bool> visited(num, false);
    // int mask = (1 << n) - 1;
    for(int i = n;i>=0;i--){
        ll mask = (1LL<<i)-1;
        for(ll j =0;j<num;j++){
            if(((mask&j)==mask) && !visited[j]){
                ans.push_back(j);
                visited[j] = true;
            }
        }
    }
    for(int i = 0; i<num; i++){
        cout<<ans[i]<<" ";
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
