#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    ll ans = 0;
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    if(n==2){
        cout<<"9"<<endl;
        return;
    }
    if(n==3 || n==4){
        ans = 4*n*n - n - 4; 
    }
    if(n>=5){
        ans = 5*n*n - 5*n - 5;
    }
    cout<<ans<<endl;
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