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
for(int i =  0;i<n;i++)
#define py cout<<"YES\n";
#define pn cout<<"NO\n";

const ll MOD = 1000000007;
const int MAXN = 200005;

ll pw2[MAXN];

void solve() {
    int n;
    cin>>n;

    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ind = 0;
    int sz = 0;

    while(ind < n && a[ind] == -1){
        sz++;
        ind++;
    }

    int q = 0, adj = 0, prev = -1;

    while (ind<n) {
        int v = a[ind];
        int c = 0;

        while (ind<n && a[ind]== v) {
            c++;
            ind++;
        }

        if (q>0 && v==prev + 1)
            adj++;

        prev = v;
        q++;
    }

    int p = q+(sz> 0 ? 1 : 0);
    ll comp = (sz>0)?(1 + adj) : 1;
    ll ans = comp % MOD * pw2[n - p] % MOD;

    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pw2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pw2[i] = pw2[i - 1] * 2 % MOD;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}