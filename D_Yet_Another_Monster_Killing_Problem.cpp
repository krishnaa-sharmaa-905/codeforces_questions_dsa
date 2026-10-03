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
    cin >> n;

    vll a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll m;
    cin >> m;

    vll hero(n+1,0);
    for(ll i = 0; i < m; i++){
        ll x,y;
        cin >> x >> y;
        hero[y] = max(hero[y],x);
    }

    vll bestk(n+1);
    bestk[n] = hero[n];

    for(ll i = n-1; i > 0; i--){
        bestk[i] = max(bestk[i+1], hero[i]);
    }

    ll pos = 0;
    ll ans = 0;

    while(pos < n){
        ll mx = 0;
        ll len = 0;

        while(pos + len < n){
            mx = max(mx, a[pos + len]);

            if(bestk[len + 1] < mx)
                break;

            len++;
        }

        if(len == 0){
            cout << -1 << endl;
            return;
        }

        pos += len;
        ans++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}