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
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    vi prefa(n + 1, 0);
    vi prefb(n + 1, 0);
    vi pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if(a[i]=='0'){
            prefa[i] = prefa[i-1]+1;
        }
        if(b[i]=='0'){
            prefb[i] = prefb[i-1]+1;
        }        
        if(a[i]=='0' && b[i]=='0'){
            pref[i]= pref[i-1]+1;
        }
        
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int za = prefa[r] - prefa[l - 1];
        int zb = prefb[r] - prefb[l - 1];
        int zcomm = pref[r] - pref[l - 1];

        int len = r - l + 1;

        int oa = len - za;
        int ob = len - zb;

        int extraA = max(0, za - oa);
        int extraB = max(0, zb - ob);

        if (extraA + extraB <= 2 * zcomm){
            py;
        }
        else{
            pn;
        }
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