#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> ans(n+1);
    for(int i = 1; i<n+1; i++){
        int cal = (l+i-1)/i;
        cal =  cal*i;
        if(cal<=r){
            ans[i] = cal;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 0; i<n; i++){
        cout<<ans[i+1]<<" ";
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