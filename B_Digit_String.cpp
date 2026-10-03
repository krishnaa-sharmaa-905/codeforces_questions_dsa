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
    string a;
    int odd = 0;
    int ans = 0;
    for(int i = 0;i<s.size();i++){
        char ch = s[i];
        if(ch=='4') ans++;
        else{
            a.push_back(ch);
            if(ch=='3' || ch=='1') odd++;
        }
    }
    int n = a.size();

    int maxi = odd;
    int even = 0;
    for(int i= 0 ;i<n;i++){
        char ch = a[i];
        if(ch=='2'){
            even++;
        }
        else{
            odd--;
        }
        maxi=  max(maxi,odd+even);
    }

    ans += (n-maxi);
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