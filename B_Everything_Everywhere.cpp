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

void solve() {
    int n;
    cin>>n;
    vi a(n);
    int ans= 0;
    for(int i = 0; i<n; i++) cin>>a[i];
    int i =  0;
    int j =  1;
    while(j<n){
        if(a[i]%(a[j]-a[i])==0) ans++;
        i++;
        j++;
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