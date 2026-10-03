#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

bool isPrime(ll num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (ll i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(ll a, ll b) {
    return (1LL * a / gcd(a, b)) * b;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> pre(n,0),neg(n,0);
    ll negsum=0,possum=0;



    for(ll i=0;i<n;i++){
        if(a[i]>0){
            possum+=a[i];
        }
        else{
            negsum-=a[i];
            
        }
        pre[i] = possum;
        neg[i] = negsum;
 
    }
    ll ans= max(possum, negsum);;
for(ll i=0;i<n;i++){
    
  ans = max(ans, pre[i] + negsum - neg[i]);
}
cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}