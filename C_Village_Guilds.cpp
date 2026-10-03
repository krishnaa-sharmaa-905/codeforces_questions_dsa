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

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(int a, int b) {
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
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    vector<int> dp(n + 1, 0);

    for (int i = n; i >= 1; i--) {
        int mx = -1;
        for (auto it : adj[i]) {
            mx = max(mx, dp[it]);
        }

        if (mx != -1)
            dp[i] = mx + 1;
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans++;

        if (adj[i].size() < 2)
            continue;

        int mx1 = -1, mx2 = -1;

        for (auto it : adj[i]) {
            if (dp[it] >= mx1) {
                mx2 = mx1;
                mx1 = dp[it];
            } else if (dp[it] > mx2) {
                mx2 = dp[it];
            }
        }

        ans += mx2 + 1;
    }

    cout << ans <<endl;
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