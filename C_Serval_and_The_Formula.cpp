#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;


void solve() {
    ll x, y;
    cin >> x >> y;
    if(x==y){
        cout<<"-1"<<endl;
        return;
    }
    ll maxi = max(x,y);
    
    ll num = 1;
    while (num <= maxi) {
        num *= 2;
    }
    
    ll k = num-maxi;
    cout<<k<<endl;

    
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