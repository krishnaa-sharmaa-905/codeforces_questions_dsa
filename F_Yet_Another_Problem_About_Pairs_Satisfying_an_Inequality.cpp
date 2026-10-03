#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> nums;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]<i+1){
            nums.push_back(i+1);
        }
    } 
    ll ans = 0;
    for(ll i = 0;i<nums.size();i++){
        ans += lower_bound(nums.begin(),nums.end(),a[nums[i]-1]) - nums.begin();
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}