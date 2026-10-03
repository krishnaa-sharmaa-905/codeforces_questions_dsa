#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,w;
    cin>>n>>w;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> power(22);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<22;j++){
            if(( a[i] & (1<<j) )){
                power[j]++;
            }
        }
    }
    int used = 0;
    int ans = 0;
    while(used<n){
        int temp = w;
        for(int i = 21;i>=0;i--){
            while(power[i]>0 && temp >= (1<<i)){
                power[i]--;
                temp -= (1<<i);
                used++;
            }
        }
        ans++;
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