#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> ans(n+1);
    int cnt = 0;
    ans[n] = 1;
    ans[0] = -1;
    int i=  1;
    while(n>i){
        if(i%2==1){
            ans[n-i]=  ans[n-i+1] + (n-i);
        }
        else{
            ans[n-i]=  ans[n-i+1] - (n-i);
        }
        i++;
    }
    for(int i = 1;i<=n;i++){
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