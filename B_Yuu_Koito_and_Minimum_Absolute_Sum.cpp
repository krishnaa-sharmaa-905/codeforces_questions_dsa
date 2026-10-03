#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    if(a[0]==-1 || a[n-1]==-1){
        ans = 0;
        if(a[0]==-1 && a[n-1]==-1){
            a[0] = 0;
            a[n-1] = 0;
        }
        else if(a[0]==-1){
            a[0] = a[n-1];
        }
        else{
            a[n-1] = a[0];
        }
    }
    
    else{
        ans = abs(a[0]-a[n-1]);
    }
    for(int i = 1;i<n-1;i++){
        if(a[i]==-1){
            a[i] =0;
        }
    }
    cout<<ans<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

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