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

bool check(ll time, vector<ll>& worker){
    ll extra = 0;
    ll n = worker.size();
    ll need = 0;
    for(ll i = 0;i<n;i++){
        if(time>=worker[i]){
            extra += (time-worker[i])/2;
        }
        else{
            need += worker[i]-time;
        }
    }
    if(need<=extra) return true;
    return false;
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vll a(m);
    for(ll i = 0; i<m; i++) cin>>a[i];
    vll worker(n);
    for(ll i =  0;i<m;i++){
        worker[a[i]-1]++;
    }

    ll s = 0;
    ll e = 2*m;
    ll ans = 0;
    while(e>=s){
        ll time = s+ (e-s)/2;
        if(check(time,worker)){
            ans = time;
            e = time-1;
        }
        else{
            s= time+1;
        }
    }

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