#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll q;
    cin >> q;
    vector<vector<ll>> queries(q, vector<ll>(2));
    for(ll i = 0; i < q; i++){
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<vector<ll>> precal(n+1, vector<ll>(33, 0));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j < 33; j++){
            precal[i][j] = precal[i-1][j];
            if(a[i-1] & (1 << (j-1))){
                precal[i][j]++;
            }
        }
    }

    for(ll i = 0; i < q; i++){
        ll ans = -1;
        ll l = queries[i][0] - 1;
        ll k = queries[i][1];
        ll start = l;
        ll end = n - 1;

        while(start <= end){
            ll mid = start + (end - start) / 2;
            long long value = 0;

            for(ll j = 1; j < 33; j++){
                ll setbit = precal[mid+1][j] - precal[l][j];
                if(setbit == mid - l + 1){
                    value |= (1LL << (j-1));
                }
            }

            if(value >= k){
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if(ans == -1) cout << -1 << " ";
        else cout << ans + 1 << " ";
    }

    cout << endl;
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