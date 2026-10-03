#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
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
    
    int m = 2 * n;
    vi a(m + 1);
    vi first(n + 1, 0);
    vi last(n + 1, 0);
    
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (first[a[i]] == 0) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }
    
    vvi end_at(m + 1);
    for (int i = 1; i <= n; i++) {
        end_at[last[i]].push_back(i);
    }
    
    vll dp(m + 1, 0);
    
    for (int i = 1; i <= m; i++) {
        dp[i] = dp[i - 1];
        
        for (int v : end_at[i]) {
            int L = first[v];
            int R = last[v];
            ll len = R - L + 1;
            ll weight = 1LL*len * len - 1LL*len;
            
            dp[i] = 1LL*max(dp[i], dp[L - 1] + weight);
        }
    }
    
    cout << dp[m] + m << "\n";
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