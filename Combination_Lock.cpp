#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



void solve() {
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"-1"<<endl;
        return;
    }
    vector<int> ans;
    for(int i = 1; i<=n; i++){
        int num = (2*(i-1))%n+1;
        ans.push_back(num);
    }
    int size = ans.size();
    for(int i = 0; i<size; i++){
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