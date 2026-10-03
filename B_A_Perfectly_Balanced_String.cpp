#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    int k;
    unordered_map<char,int> mpp;
    for(k = 0;k<n;k++){
        if(mpp.find(s[k])==mpp.end()){
            mpp[s[k]]++;
        }
        else{
            break;
        }
    }
    for(int i=k;i<n;i++){
        if(s[i]!=s[i-k]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

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