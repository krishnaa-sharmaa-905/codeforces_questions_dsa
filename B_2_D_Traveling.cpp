#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

void solve() {
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<vector<ll>> coord;
    for(ll i = 0; i<n; i++){
        vector<ll> temp;
        for(ll j = 0;j<2;j++){
            ll num;
            cin>>num;
            temp.push_back(num);

        }
        coord.push_back(temp);

    }
    //input taken


    //dist b/w a and nearest major city
    ll ax =coord[a-1][0];
    ll ay = coord[a-1][1];
    ll bx =coord[b-1][0];
    ll by = coord[b-1][1];

    ll dista = LLONG_MAX / 2;
    ll distb = LLONG_MAX / 2;
    if(b<=k){
        distb = 0;
    }
    if(a<=k){
        dista = 0;
    }
    
        
        for(ll i =0;i<k;i++){
            ll currx = coord[i][0];
            ll curry = coord[i][1];
            dista = min(dista,(abs(ax-currx)+abs(ay-curry)));
            distb = min(distb,(abs(bx-currx)+abs(by-curry)));
        }
    ll ans = dista+distb;
    ans = min(ans, abs(ax-bx)+abs(ay-by));
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