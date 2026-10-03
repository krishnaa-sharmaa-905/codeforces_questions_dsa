#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        sum+= a[i];
    }

    vector<ll> mini(n);
    mini[n-1] = a[n-1];
    sum-=a[n-1];
    for(ll i = n-2;i>=0;i--){
        mini[i] = 1LL*min(mini[i+1],a[i]);
        sum -= mini[i];
    }

    ll conti = 1;
    ll curr = 1;
    for(ll i = 1;i<n;i++){
        if(mini[i]==mini[i-1]) curr++;
        else{
            conti = 1LL*max(conti,curr);
            curr = 1;
        }
    }
    conti = 1LL*max(conti,curr);

    cout<<sum+conti-1<<endl;

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