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
    int n;
    cin>>n;
    vi a(n);
    for(int i  = 0;i<n;i++){
        cin>>a[i];
    }
    ll curr = 0;
    for(int i = 0; i<n; i++){
        curr = curr + (a[i]-i-1);
        if(curr<0){
            pn;
            return;
        }
    }
    py;
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