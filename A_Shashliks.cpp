#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;
    int mini=  INT_MAX;
    int mindeg = INT_MAX;
  
    bool flag = true;
    
     if(x>y){
        swap(a,b);
        swap(x,y);
     }
     int ans = 0;
     if(k>=a){
        ans += (k-a)/x  +1;
     }
     k -= ans*x;
     if(k>=b){
        ans += (k-b)/y +1;
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