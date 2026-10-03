#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    ll l=0;
    ll r = n-1;
    ll ans =0;
    while(r>l){
        ll curr = abs(a[r]-a[l]);
        ans = gcd(ans,curr);
        r--;
        l++;
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