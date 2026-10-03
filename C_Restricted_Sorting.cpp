#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)cin>>a[i];
    vector<int> sorted = a;
    sort(sorted.begin(),sorted.end());
    if(sorted==a){
        cout<<"-1"<<endl;
        return;
    }
    int mini = sorted[0];
    int maxi = sorted[n-1];
    int s = 1;
    int e = maxi - mini;
    int ans = -1;
    while(s<=e){
        int m = s + (e-s)/2;
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(a[i]==sorted[i]){
                continue;
            }
            else{
                if(a[i] - mini <m  && maxi - a[i]<m){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ans = m;
            s = m + 1;
        }
        else{
            e = m - 1;
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