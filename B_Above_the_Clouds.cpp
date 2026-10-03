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
    string s;
    cin>>s;
    unordered_map<char,int> mpp;
    for(int i = 0; i<n; i++){
        mpp[s[i]]++;
    }
    for(int i = 1;i<n-1;i++){
        // b ke liye
        if(mpp[s[i]]>1){
             cout<<"YES"<<endl;
                return;
        }
    }
    cout<<"NO"<<endl;
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