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
    ll n;
    cin>>n;
    vll a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];

    ll maxi = -1e9 - 1;
    ll diff = -1e9-1;
    ll ans = 0;

    for(ll i =  0;i<n;i++){
         maxi = max(a[i],maxi);
         diff = max(diff,maxi - a[i]);
    }
    ans = (ll)(ceil(log2(diff+1)));
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