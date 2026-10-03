#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    string s;
    cin>>s;
    int n = s.size();

    string ans = s;
    

    for(int i  = 1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans[i] = s[i];
            continue;
        } 

        for(int j = 0;j<26;j++){
            char ch = 'a' + j;
            if(s[i-1] != ch){
                if(i<n-1 && s[i+1]!=ch){
                    s[i] = ch;
                    ans[i] = ch;
                    break;
                }
                else if(i==n-1){
                    s[i] = ch;
                    ans[i] = ch;
                    break;
                }
            }
        }
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}