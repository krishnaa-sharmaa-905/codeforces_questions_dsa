#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
typedef double ll;



void solve() {
    ll n,c;
    cin>>n>>c;
    vector<ll> s(n);
    vector<ll> ssq(n);
    ll ssum =0;
    ll ssqsum = 0; 
    for(ll i = 0; i<n; i++){
        cin>>s[i];
        ssqsum += s[i]*s[i];
        ssum +=s[i];
    }
    
    ll z = ssqsum-c;
    ll b = 4.0*ssum;
    ll a = 4.0*n;
    ll d = b*b -4.0*a*z;
    ll D = sqrt(d);
    ll ans = (-b + D) / (2.0 * a);
    cout << fixed << setprecision(0)<<ans<<endl;
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