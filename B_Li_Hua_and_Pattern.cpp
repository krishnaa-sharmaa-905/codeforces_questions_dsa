#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    int k;
    cin>>n>>k;
    vector<vector<int>> a;
    for(int i  =0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            temp.push_back(num);
        }
        a.push_back(temp);        
    }
    int diff = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j]!=a[n-i-1][n-j-1]){
                diff++;
            }
        }
    }
    diff = diff/2;
    if(diff>k){
        cout<<"NO"<<endl;
        return;
    }
    if(n%2==1){
        cout<<"YES"<<endl;
        return;
    }
    else{
        
        int krem = k-diff;
        if(krem%2==0){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
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