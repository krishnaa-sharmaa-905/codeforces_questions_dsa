#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> setbit;
    unordered_map<int,int> mpp;
    for(int i = 0; i<n; i++){
        int ki;
        cin>>ki;
        vector<int> temp(ki);
        for(int j = 0;j<ki;j++){
            cin>>temp[j];
            mpp[temp[j]]++;
        }
        setbit.push_back(temp);
    }

    for(int i = 0;i<n;i++){
        bool possible = true;
        for(auto it:setbit[i]){
            if(mpp[it]<2){
                possible = false;
                break;
            }
        }
        if(possible==true){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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