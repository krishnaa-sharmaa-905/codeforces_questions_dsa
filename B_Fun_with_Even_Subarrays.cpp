#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int ele = a[n-1];
    int ans = 0;
    int r = n-1;
    while(r>=0){
        if(a[r]==ele){
            r--;
        }
        else{
           int k = n-r-1;
            ans++;
            r=r-k;
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