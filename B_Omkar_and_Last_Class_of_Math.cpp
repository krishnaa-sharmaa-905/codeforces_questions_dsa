#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

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
    if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
        return;
    } 
    ll s = n/2;
    ll e = s+1;
    ll mini = LLONG_MAX;
    while(s>=1 && e<=n-1){
        if(lcm(s,e) <= n){
            cout<<s<<" "<<e<<endl;
            return;
        }
        s--;
        e++;
    }

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