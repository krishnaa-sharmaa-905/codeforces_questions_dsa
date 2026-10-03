#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second

#define py cout<<"YES\n";
#define pn cout<<"NO\n";

const ll MOD = 1000000007;

bool isPrime(ll num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (ll i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

vector<bool> sieve(ll n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (1LL * a / gcd(a, b)) * b;
}

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

bool isSquare(ll x) {
    ll r = sqrt(x);
    return r * r == x;
}

void solve() {
    ll n;
    cin >> n;

    vll a(n), d(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> d[i];

    vll ans(n, -1);
    for(ll val = n; val >= 1; val--) {
        ll idx = -1;

        
        for(ll i = 0; i < n; i++) {
            if(ans[i]==-1 && d[i] == 0) {
                idx = i;
                break;
            }
        }
        // cout<<idx<<" ";
        if(idx == -1) {
            cout << -1 << endl;
            return;
        }

        ans[idx] = val;
        for(ll j = 0; j < idx; j++) {
            if(ans[j]==-1 && a[j] < a[idx]) {
                d[j]--;
                // cout<<j<<" "<<d[j];
            }
        }
    }

    for(auto it : ans) cout << it << " ";
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