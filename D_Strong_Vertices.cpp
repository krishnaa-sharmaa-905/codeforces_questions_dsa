#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];
    vector<vector<int>> diff(n,vector<int>(2));
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        diff[i][0] = a[i]-b[i];
        diff[i][1] = i;
        maxi = max(maxi,diff[i][0]);
    }
    sort(diff.begin(),diff.end());
    vector<int> ans;
    int i=n-1;
    while(i>=0){
        if(diff[i][0]==maxi){
            ans.push_back(diff[i][1]);
        }
        else{
            break;
        }
        i--;
    }
    reverse(ans.begin(),ans.end());
    cout<<(int)ans.size()<<endl;
    for(int i =  0;i<ans.size();i++){
        cout<<ans[i]+1<<" ";
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