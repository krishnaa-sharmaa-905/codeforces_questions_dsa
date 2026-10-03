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

void solve() {
    ll n;
    cin>>n;
    vll a(n);
    for(int i = 0; i<n; i++)cin>>a[i];
    vll ans(n);
    ans[0] = a[0];
    ll sum = a[0];
    for(int i = 1; i<n; i++){
        sum+=a[i];
        ans[i] = min(ans[i-1],sum/(i+1));
    }
    for(int i = 0; i<n; i++)cout<<ans[i]<<" ";
    cout<<endl;
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