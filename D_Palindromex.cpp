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

int help(int i, int j, vector<int>& a){
    int n = a.size();
    int q = n/2;
    int ans = 1;
    vector<bool> center1(q+1,false);
    while(i>=0 && j<n){
        if(a[i]==a[j]){
            center1[a[i]] = true;
            j++;
            i--;
        }
        else{
            break;
        }
    }
    for(int i = 0;i<=q;i++){
        if(center1[i]==false){
            ans= max(ans,i);
            break;
        }
    }
    return ans;
}

void solve() {
    int q;
    cin>>q;
    int n = 2*q;
    vector<int> a(n);
    int ind1 = -1,ind2 = -1;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(ind1==-1 && a[i]==0){
            ind1 = i;
        }
        else if(ind1!=-1 && a[i]==0){
            ind2 = i;
        }
    }
    int ans = 1;
    //center at ind1;
    ans=  max(ans,help(ind1,ind1,a));
    //center at ind2;
    ans=  max(ans,help(ind2,ind2,a));
    //center int b/w ind1 and ind2;
    int diff = ind2-ind1;
    if((diff)%2==0){
        ans = max(ans,help(ind1 + ((diff)/2) ,ind1 + ((diff)/2), a));
    }
    else{
        ans = max(ans, help(ind1 + ((diff)/2), ind1 + ((diff)/2) + 1, a));
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