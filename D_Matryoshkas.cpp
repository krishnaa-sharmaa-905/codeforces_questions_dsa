#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<set>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mpp;
    set<int> b;
    int ans = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
        b.insert(a[i]);
        b.insert(a[i]+1);
    }
    int prev = 0;

    for(auto it:b){
        int curr = mpp[it];
        ans += max(0,curr-prev);
        prev = curr;
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
