#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;



int findMEX(vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end()); 
    int mex = 0;
    while (s.count(mex)) mex++; 
    return mex;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<pair<int,int>> ans;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<int> temp;
    if(n>4){
    
    temp.assign(a.begin(),a.begin()+n-3);
    int mex = findMEX(temp);
    a.erase(a.begin(),a.begin()+n-4);
    a[0] = mex;
    pair<int,int> start = {1,n-3};
    ans.push_back(start);
    }   
   
    int r = 4;
    if(a[2]==0 || a[3]==0){
        ans.push_back({3,4});
        r-=1;
    }
    if(a[0]==0 || a[1]==0){
        ans.push_back({1,2});
        r-=1;
    }
    
        ans.push_back({1,r});
    
   
    cout<<ans.size()<<endl;
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
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