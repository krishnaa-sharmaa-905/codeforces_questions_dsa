#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i].first*a[j].first>2*n) break;

            else if(a[i].first*a[j].first == a[i].second + a[j].second){
                ans++;
            }
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