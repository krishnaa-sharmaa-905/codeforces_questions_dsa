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
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    int loc = a[n/2];
    int i = n/2;
    int j = i;
    int ans =0;
    while(j<n && a[j]==loc){
        j++;
    }
    while(i>=0 && a[i]==loc){
        i--;
    }
    ans += min(n-j,i+1);
    int rem = max(n-j-ans, i+1-ans);
    ans += rem;
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