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

void print(vector<int>& a){
    for(int i= 0 ;i<a.size();i++){
        cout<<a[i];
    }
    cout<<endl;
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

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int open = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='('){
            open++;
        }
    }
    vector<int> ans(n);
    if(open==0 || open==n || k==0){
        print(ans);
        return;
    }
    stack<int> st;
    for(int i = 0;i<n && k>0 ;i++){
        if(s[i]=='('){
            st.push(i);
        }
        else{
            if(!st.empty()){
                int ind=  st.top();
                if(open<=n-open){
                    ans[ind] = 1;
                    k--;
                    st.pop();
                }
                else{
                    ans[i] = 1;
                    k--;
                }
            }
            else{
                continue;
            }
        }
    }
    print(ans);
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