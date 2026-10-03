#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int mini = 1;
    int maxi = 3*n;
    vector<int> ans(3*n);
    for(int i = 0;i<3*n-2;i = i+3){
        ans[i] = mini;
        ans[i+1] = maxi-1;
        ans[i+2] = maxi;
        mini++;
        maxi = maxi-2;
    }
    for(auto it:ans){
        cout<<it<<" ";
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