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

bool static comp(ll& a, ll& b){
    return a>b;
}

void solve() {
    ll n;
    cin>>n;
    vll u(n),s(n);
    for(ll i = 0; i<n; i++) cin>>u[i];
    for(ll i =0;i<n;i++) cin>>s[i];

    vector<vector<ll>> uniwise(n+1);
    for(ll i = 0;i<n;i++){
        uniwise[u[i]].push_back(s[i]);
    }
    vll ans(n+1,0);
    for(ll i = 1;i<n+1;i++){
        sort(uniwise[i].begin(),uniwise[i].end(),comp);

        vll pref(uniwise[i].size()+1,0);
        for(ll j = 0; j<uniwise[i].size();j++){
            pref[j+1] = pref[j] + uniwise[i][j];
        }
        ll sz = uniwise[i].size();
        for(ll k = 1;k<=sz;k++){
            ll usable = (sz/k)*k;
            ans[k] += pref[usable];
        }
    }

    for(ll k= 1;k<=n;k++){
        cout<<ans[k]<<" ";
    }
    cout<<endl;

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