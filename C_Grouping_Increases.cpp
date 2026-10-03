#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    int x = INT_MAX;
    int y = INT_MAX;
    int ans = 0;
    for(int i= 0;i<n;i++){
        if(x>y){
            swap(x,y);
        }
        if(a[i]<=x){
            x = a[i];
        }
        else if(a[i]<=y){
            y = a[i];
        }
        else{
            ans++;
            x = a[i];
            
        }
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