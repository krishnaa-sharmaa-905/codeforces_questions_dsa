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
    vll a(n),b(m);
    for(ll i = 0; i<n; i++) cin>>a[i];
    for(ll i  = 0;i<m;i++){
        cin>>b[i];
        b[i]--;
    }
    sort(b.begin(),b.end());
    vll pref(n);
    pref[0] = a[0];
    for(ll i  = 1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    ll ans = 0;
    for(ll i = 0;i<m;i++){
        if(i==0){
            ans += abs(pref[b[i]]);
        }
        else{
            ans += abs(pref[b[i]]-pref[b[i-1]]);
        }
    }

    ans += (pref[n-1] - pref[b[m-1]]);
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