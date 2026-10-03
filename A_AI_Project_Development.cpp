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
    ll n,x,y,z;
    cin>>n>>x>>y>>z;
    ll t1 = (n+(x+y)-1)/(x+y);
    ll t2 = (n-1LL*(z*x) + (x+1LL*10*y)-1)/(x+1LL*10*y) + z;
    ll ans = 1LL*min(t1,t2);
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