#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<ll> numreq;
    ll grps = 1;
    sort(a.begin(),a.end());
    for(ll i = 1;i<n;i++){
        if(a[i]-a[i-1]<=x) continue;
        else{
            grps++;
            ll d = a[i] - a[i-1];
            ll temp = ((d+x-1)/x) -1;
            numreq.push_back(temp);
        }
    }
    sort(numreq.begin(),numreq.end());

    for(ll i  = 0;i<numreq.size();i++){
        if(numreq[i]<=k){
            k-=numreq[i];
            grps--;
        }
        else{
            break;
        }
    }
    cout<<grps<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}