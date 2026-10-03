#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    string p;
    string s;
    cin>>p>>s;
    int n = p.size();
    int m = s.size();
    if(n==m){
        for(int i = 0; i<n; i++){
            if(s[i]!=p[i]){
                cout<<"NO"<<endl;
                return;
            }
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