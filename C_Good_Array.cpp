#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    unordered_map<ll,ll> mpp;
    for(ll i = 0; i<n; i++) {
        cin>>a[i];
        mpp[a[i]]++;
    }
    vector<ll> ans;
    ll total = 1LL*accumulate(a.begin(),a.end(),0*1LL);
    for(ll i = 0;i<n;i++){
        ll temp = total - a[i];
        if(temp%2==1) continue;
        temp = temp/2;
        if(mpp.find(temp)!=mpp.end()){
            if(mpp[temp]>1) ans.push_back(i);
            else if(a[i]!=temp) ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(ll i = 0; i<(ll)ans.size(); i++) cout<<ans[i]+1<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}