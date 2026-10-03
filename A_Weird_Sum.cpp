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

const ll MOD = 1000000007;


void solve() {
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,vll> mppx,mppy;
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            ll a;
            cin>>a;
            mppx[a].pb(i);
            mppy[a].pb(j);
        }
    }
    ll ans = 0;
    for(auto it:mppx){
        vll ind = it.ss;
        sort(ind.begin(),ind.end());
        ll sub=  ind[0];
        for(ll i = 1;i<ind.size();i++){
            ans += 1LL*i*ind[i] - sub;
            sub += ind[i];
        }
    }
    for(auto it:mppy){
        vll ind = it.ss;
        sort(ind.begin(),ind.end());
        ll sub=  ind[0];
        for(ll i = 1;i<ind.size();i++){
            ans += 1LL*i*ind[i] - sub;
            sub += ind[i];
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}