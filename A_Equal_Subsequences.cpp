#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(1);
    }
    for(int i=k;i<n;i++){
        ans.push_back(0);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    ll ans = LongLong_MIN;
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