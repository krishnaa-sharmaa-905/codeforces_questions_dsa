#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;


void solve() {
    int n;
    int m;
    cin>>n>>m;
    int sum =0;
    int mini = 1e9;
    int neg = 0;

    vector<vector<int>> nums(n,vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j= 0;j<m;j++){
            cin>>nums[i][j];
            int curr = nums[i][j];
            sum +=abs(curr);
            if(curr<0){
                neg++;

            }
            mini = min(abs(curr),mini);
        }
    }
    
    
    
 
  
    if(neg%2==0){
        cout<<sum<<endl;
        
    }
    else{
        cout<<sum-2*mini<<endl;
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