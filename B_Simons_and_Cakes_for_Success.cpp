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
    ll n;
    cin>>n;
    unordered_set<ll> st;
    ll ans = 1;
    for(ll i = 2;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            while(n%i==0){
                n = n/i;
            }
        }
    }

    if(n>1){
        st.insert(n);
    }

    for(auto it:st){
        ans *= it;
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