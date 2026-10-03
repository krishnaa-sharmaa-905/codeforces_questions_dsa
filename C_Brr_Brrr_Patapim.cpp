#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> g;
    for(int i = 0; i<n; i++){
        vector<int> temp;
        for(int i = 0; i<n; i++){
            int num;
            cin>>num;
            temp.push_back(num);
        }
        g.push_back(temp);
    }
    vector<int> check(2*n+2,-1);

    vector<int> ans(2*n+2);
    for(int i = 0; i<n; i++){
        for(int j = i;j<n;j++){
            int ind = i+j+2;
            ans[ind] = g[i][j];
            check[g[i][j]] = 0;
        }
    }

    for(int i = 1; i<2*n+1; i++){
        if(check[i]==-1){
            ans[1] =i;
            break;
        }
    }
    for(int i = 1; i<2*n+1; i++){
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