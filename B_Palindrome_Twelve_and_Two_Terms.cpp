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

    if (n == 10) {
        cout << -1 << '\n';
        return;
    }

    ll r = n % 12;

    if (r <= 9) {
        cout << r << ' ' << n - r << '\n';
    } else if (r == 11) {
        cout << 11 << ' ' << n - 11 << '\n';
    } else { 
        if (n < 22) cout << -1 << '\n';
        else cout << 22 << ' ' << n - 22 << '\n';
    }
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