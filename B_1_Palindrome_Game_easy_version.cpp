#include <bits/stdc++.h>
using namespace std;
#define alice cout<<"ALICE"<<endl;
#define bob cout<<"BOB"<<endl;
#define draw cout<<"DRAW"<<endl;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zero = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='0'){
            zero++;
        }
    }
    if(zero%2==0  || zero==1){
        bob;
    }
    else{
        alice;
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