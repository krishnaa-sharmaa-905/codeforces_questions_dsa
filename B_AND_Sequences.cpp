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

const ll MOD = 1000000007LL;

#define py cout<<"YES\n";
#define pn cout<<"NO\n";

vll fact;
int n;
void precompute(){
    fact[0] = 1;
    for(int i = 1;i<=n;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

void solve() {
    cin>>n;
    vi a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    fact.resize(n+1);
    precompute();
    int x = a[0];
    for(int i = 1; i<n; i++){
        x = x&a[i];
    }
    ll cnt = 0;
    for(int i = 0; i<n; i++){
        if(x==a[i]) cnt++;
    }
    if(cnt<2){
        cout<<"0"<<endl;
        return;
    }
    ll ans = cnt;
    ans = (ans*(cnt-1))%MOD;
    ans = (fact[n-2]*ans)%MOD;
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