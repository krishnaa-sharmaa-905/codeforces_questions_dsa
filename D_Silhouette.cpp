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
    ll n;
    cin>>n;
    vll b(n);
    for(ll i = 0; i<n; i++) cin>>b[i];
    map<ll,ll> mpp;
    map<ll,ll> a;
    for(ll i = 0; i<n; i++){
        a[b[i]] += 1;
    }
    vector<pll> shadow;
    for(auto &it:a){
        shadow.push_back({it.ff,it.ss});
    }
    // sort(shadow.begin(),shadow.end());
    ll s = shadow.size();
    
    if(shadow[0].ff !=0){
        cout<<"-1"<<endl;
        return ;
    }
   
    ll maxi = 0;
    for(ll i = 1;i<s;i++){
        if((shadow[i].ff - shadow[i-1].ff)%shadow[i-1].ss !=0 ) {
            cout<<"-1"<<endl;
            return;
        }
        else{
            ll num = (shadow[i].ff - shadow[i-1].ff) / shadow[i-1].ss;
            if(num<=maxi){
                cout<<"-1"<<endl;
                return;
            }
            mpp[shadow[i-1].ff] = num;
            maxi = 1LL*max(num,maxi);
        }
    }
    mpp[shadow[s-1].ff] = maxi+1;

    // vi ans(n);
    for(ll i = 0; i<n;i++){
        cout<<mpp[b[i]]<<" ";
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

