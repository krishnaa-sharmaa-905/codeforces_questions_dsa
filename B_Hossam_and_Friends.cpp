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
    // cout<<"test";
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> notfrnd(m,vector<ll>(2));
    for(ll i  = 0;i<m;i++){
        cin>>notfrnd[i][0]>>notfrnd[i][1];
        if(notfrnd[i][1]<notfrnd[i][0]){
            swap(notfrnd[i][0],notfrnd[i][1]);
        }
    }
    vector<ll> b(n,n);
    ll ans = 0;
    for(ll i=  0;i<m;i++){
        ll a = notfrnd[i][0]-1;
        ll other = notfrnd[i][1]-1;
        // cout<<i<<" ";
        // cout<<a<<" "<<other<<endl;
        
        
        b[a] = min(b[a],other);
        
    }
    // for(ll i = 0; i<n; i++)cout<<b[i]<<" ";
    // cout<<endl;
    for (ll i = n - 2; i >= 0; i--) {
        b[i] = min(b[i], b[i + 1]);
    }
    for(ll i = 0; i<n; i++){
        if(b[i]==-1) ans += n-i;
        else{
            ans += b[i]-i;
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