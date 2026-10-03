#include <bits/stdc++.h>
using namespace std;

void solve() {
    //  kill in order from 1 to k
    int n;
    cin>>n;
    vector<vector<int>> cave;
    vector<vector<int>> each_cave;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        vector<int> temp(k);
        for(int j = 0;j<k;j++){
            cin>>temp[j];
            temp[j] = temp[j] - j + 1;
        }
        sort(temp.begin(),temp.end());
        cave.push_back(temp);
        each_cave.push_back({temp[k-1],k});

    }
    sort(each_cave.begin(),each_cave.end());
    int ans = each_cave[0][0];
    int mons = each_cave[0][1];
    for(int i = 1;i<n;i++){
        ans = max(ans,each_cave[i][0] - mons);
        mons += each_cave[i][1];
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