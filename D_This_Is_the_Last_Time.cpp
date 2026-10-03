#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n,k;
    cin>>n>>k;
    vector<pair<int,pair<int,int>>> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i].first>>v[i].second.first>>v[i].second.second;
    }
    sort(v.begin(),v.end());
    int ans = k;
    for(int i = 0; i<n; i++){
        if(v[i].first<=ans && v[i].second.first>=ans && v[i].second.second>ans){
            ans = max(ans,v[i].second.second);
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