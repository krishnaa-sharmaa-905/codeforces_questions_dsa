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

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(int a, int b) {
    return (1LL * a / gcd(a, b)) * b;
}

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

bool isSquare(ll x) {
    ll r = sqrt(x);
    return r * r == x;
}

int help(int diff, int ch0, int ch1){
    int maxi = -1;
    for(int d = -1;d<=1;d++){
        if(abs(diff-d) <=1 ){
            int r1 = min(ch1,ch0-d);
            int r0 = r1 + d;
            if(r1>=0 && r0>=0){
                maxi = max(maxi,r0+r1);
            }
        }
    }
    return maxi;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    int cnt0 = 0;
    int cnt1 = 0;


    for(int i = 0;i<n;i++){
        if(s[i]=='0') cnt0++;
        else{
            cnt1++;
        }
    }

    int ch0 = 0;
    int ch1 = 0;
    char ch = ' ';
    for(int i = 0;i<n;i++){
        if(s[i] != ch){
            if(s[i]=='0') ch0++;
            else{
                ch1++;
            }
            ch = s[i];
        }
    }

    int diff = 0;
    diff = cnt0-cnt1;
    int maxi = help(diff,ch0,ch1);
    
    if(maxi==-1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<n-maxi<<endl;
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