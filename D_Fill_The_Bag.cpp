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
    ll m;
    cin>>m;
    ll sum = 0;
    vi bits(62,0);
    for(ll i = 0;i<m;i++){
        ll x;
        cin>>x;
        sum += x;
        ll ind = (ll)log2(x);
        // cout<<ind<<endl;
        bits[ind]++;
    }
    if(sum < n){
        cout << -1 << endl;
        return;
    }
    // for(int i = 0 ;i<6;i++){
    //     cout<<bits[i]<<" ";
    // }
    // cout<<endl;
    ll ans = 0;

    for(ll i = 0;i<62;i++){
        if(!((n>>i) & 1LL)){
            // n has ith bit clear
            bits[i+1] += bits[i]/2;
        }
        else{
            if(bits[i] >0){
                bits[i]--;
                bits[i+1] += bits[i]/2;
            }
            else{
                ll j = i;
                while(j<62){
                    if(bits[j] >= 1){ // && ((n>>j) != 1)
                        break;
                    }
                    ans++;
                    bits[j]++;
                    j++;                    
                }
                bits[j]--;
            }

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