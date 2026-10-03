#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n;
    cin>>n;
    if(n%2==1) {
        cout<<0<<endl;
        return;
    }
    int ans = 0;
    
      int  all4 = n/4;
    
    int all2 = n/2;
    if(n%4==0) ans = all2-all4+1;
    else{
        ans = all2-all4;
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