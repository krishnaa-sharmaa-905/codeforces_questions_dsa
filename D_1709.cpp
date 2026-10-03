#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }
    vector<pair<int,int>> ans;
    
    for(int i = 0; i<n; i++){
        if(a[i]>b[i]){
            ans.push_back({3,i+1});
            swap(a[i],b[i]);
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                ans.push_back({1,j+1});
                swap(a[j],a[j+1]);
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0;j<n-i-1;j++){
            if(b[j]>b[j+1]){
                ans.push_back({2,j+1});
                swap(b[j],b[j+1]);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
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