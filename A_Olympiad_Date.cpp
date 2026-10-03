#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    unordered_map<int,int> mpp;
    mpp[0]=3;
    mpp[2]=2;
    mpp[3]=1;
    mpp[1]=1;
    mpp[5]=1;
    int l =0;
    while(mpp.size()!=0 && l<n){
        int curr=a[l];
        if(mpp.find(curr)!=mpp.end()){
            mpp[curr]--;
            if(mpp[curr]==0){
                mpp.erase(curr);
            }

        }
        l++;

    }
    if(mpp.size()==0){
        cout<<l<<endl;
    }
    else{
        cout<<0<<endl;
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