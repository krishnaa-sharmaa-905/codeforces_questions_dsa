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
    
    string s;
    cin>>s;
    int n = s.size();
    string ans = "";
    int i = 0;
    bool one = false,zero = false;
    while(i<n){
        if(!one && s[i]=='1'){
            one = true; 
            i++;
            continue;
        }
        if(!zero && s[i]=='0'){
            zero  = true;
            i++;
            continue;
        }
        ans = ans + s[i];
        i++;
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