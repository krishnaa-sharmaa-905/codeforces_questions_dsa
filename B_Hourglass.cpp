#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int s,k,m;
    cin>>s>>k>>m;
    int ans = 0;

    if(k>=s){
        int temp = m%k;
        ans = max(0,s-temp);
        cout<<ans<<endl;
        return;
    }
    else{
        int temp = m/k;
        int remtime = 0;
        if(temp%2==1){
            remtime = k - m%k;
        }
        else{
            remtime = s-m%k;
        }
        ans= remtime;
        cout<<ans<<endl;
        return;
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