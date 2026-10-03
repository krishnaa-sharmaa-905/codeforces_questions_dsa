#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second

#define py cout<<"YES\n";
#define pn cout<<"NO\n";

void solve() {
    ll n, k;
    cin>>n>>k;
    // vll a(n);
    map<ll,ll> mpp;
    for(int i = 0; i<n; i++){
        ll a;
        cin>>a;
        a = a%k;
        if(a==0){
            
            continue;
        }
        else{
            a = k-a;
            mpp[a]++;
        }
        // cout<<a[i]<<" ";
    }
    // cout<<endl;
    if(mpp.size()==0){
        cout<<"0"<<endl;
        return;
    }
    ll maxfreq = 0;
    ll maxnum  =0;
    for(auto it:mpp){
        if(maxfreq< it.ss){
            maxnum = it.ff;
            maxfreq=  it.ss;
        }
        else if(maxfreq==it.ss){
            maxnum = 1LL*max(maxnum,it.ff);
        }
    }
    // cout<<maxnum<<" "<<maxfreq<<endl;
    ll ans = 0;
    ans = maxnum+1;
    ans += k*(maxfreq-1);
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