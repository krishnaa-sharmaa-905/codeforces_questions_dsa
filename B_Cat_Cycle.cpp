#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n,k;
    cin>>n>>k;
    int ans = 0;
    if(n%2==0){
        ans = k%n;
        if(k%n==0) ans = n;
        cout<<ans<<endl;
        return;
    }
    int cnt = (n)/2;
    int extra = (k-1)/cnt;
    ans= k+extra;
    ans = ans%n;
    if(ans==0) ans=n;

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