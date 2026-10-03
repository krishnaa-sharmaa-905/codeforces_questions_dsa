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

int n;
vll val, sub;
vector<vi> adj;
ll ans;

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

bool checkSquare(ll x){
    if(x < 0) return false;

    ll rt = sqrtl(x);

    for(ll i = max(0LL, rt - 2); i <= rt + 2; i++){
        if(i * i == x) return true;
    }

    return false;
}

void dfs(int node, int par){

    sub[node] = 1;

    __int128 sum = 0;
    __int128 sqSum = 0;
    __int128 cubeSum = 0;

    for(auto child : adj[node]){

        if(child == par) continue;

        dfs(child, node);

        sub[node] += sub[child];

        __int128 cur = sub[child];

        sum += cur;
        sqSum += cur * cur;
        cubeSum += cur * cur * cur;
    }

    __int128 out = n - sub[node];

    if(out > 0){
        sum += out;
        sqSum += out * out;
        cubeSum += out * out * out;
    }

    if(checkSquare(val[node])){
        __int128 pairs = (sum * sum - sqSum) / 2;
        __int128 triples = (sum * sum * sum - 3 * sum * sqSum + 2 * cubeSum) / 6;
        ans += (ll)(pairs + triples);
    }
}

void solve(){

    cin >> n;

    val.assign(n, 0);
    sub.assign(n, 0);
    adj.assign(n, {});

    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 0; i < n - 1; i++){

        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans = 0;
    dfs(0, -1);
    cout<<ans<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}