#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int n;
    n = stoi(s);
    int ans = -1;
    for(int i = 0;i<100;i++){
        if(i*i == n){
            ans = i;
            break;
        }
    }
    if(ans!=-1){
        cout<<"0"<<" "<<ans<<endl;

    }
    else{
        cout<<"-1"<<endl;
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