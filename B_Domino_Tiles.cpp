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
    string s;
    cin>>s;
    int ans = 0;
    for (int s0 = 0; s0 <= 1; ++s0) {
        for (int s1 = 0; s1 <= 1; ++s1) {
            bool match = true;
            for (int i = 0; i < n; ++i) {
                int expected;
                if (i % 2 == 0) {
                    expected = ((i / 2) % 2 == 0) ? s0 : 1 - s0;
                } else {
                    expected = ((i / 2) % 2 == 0) ? s1 : 1 - s1;
                }
                
                if (s[i] != '?' && (s[i] - '0') != expected) {
                    match = false;
                    break;
                }
            }
            if (match) ans++;
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