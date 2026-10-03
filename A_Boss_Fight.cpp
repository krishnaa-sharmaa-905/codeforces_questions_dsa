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

void solve() {
    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    ll total = 0;
    unordered_map<int,int> mpp;
    for(auto it:a){
        mpp[it] += 1;
        total += it;
    }
    int maxi = 0;
    int cnt = 0;
    for(auto &it:mpp){
        if(it.ss>cnt){
            cnt = it.ss;
            maxi = it.ff;
        }
    }
    int extra = n-cnt;

    if(cnt<=extra+1){
        cout<<total<<endl;
    }
    else{
        ll temp = total - 1LL*maxi*cnt;
        ll ans = temp + 1LL*(extra+2)*maxi;
        cout<<ans<<endl;
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