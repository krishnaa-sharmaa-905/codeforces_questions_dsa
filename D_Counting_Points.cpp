#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;



void solve() {
    ll n;
    cin >> n; 
    ll m;
    cin>>m;
    vector<ll> xi(n);
    vector<ll> ri(n);
    for(int i = 0; i<n; i++){
        cin>>xi[i];
    }
    for(int i = 0; i<n; i++){
        cin>>ri[i];
    }

    
    map<ll, ll> mpp; 

    for (ll i = 0; i < n; i++) {
         

        for (ll x = xi[i] - ri[i]; x <= xi[i] + ri[i]; x++) {  
            ll ysq = ri[i] * ri[i] - (x - xi[i]) * (x - xi[i]);
            if (ysq < 0) continue;

            ll y = sqrt(ysq);  
            mpp[x] = max(mpp[x], y); 
        }
    }

    ll points = 0;

    for (auto [x, y] : mpp) {
        points += (2 * y + 1);  
    }

    cout << points << endl;
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