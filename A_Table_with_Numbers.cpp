#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    //x>y
    int n,h,l;
    cin>>n>>h>>l;
    vector<int> a(n);
    for(int i = 0; i<n; i++)cin>>a[i];

    int x = max(h,l);
    int y = min(h,l);
    int cntsmall = 0;
    int cntbig = 0;
    for(int i = 0; i<n; i++){
        if(a[i]<=y){
            cntsmall++;
        }
        else if(a[i]>y && a[i]<=x){
            cntbig++;
        }
    }
    int ans = 0;
    if(cntsmall<cntbig){
        ans = min(cntsmall,cntbig);
    }
    else{
        ans += cntbig;
        cntsmall -= cntbig;
        ans += cntsmall/2;
    }
    // cout<<cntsmall<<" "<<cntbig<<endl;
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