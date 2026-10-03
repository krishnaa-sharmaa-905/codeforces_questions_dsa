#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,m;
    cin>>n>>m;
    ll k = 1;
    ll cnt2= 0 ;
    ll cnt5 = 0;
    ll og = n;
    while(n && n%2==0){
        cnt2++;
        n = n/2;
    }
    while(n && n%5==0){
        cnt5++;
        n = n/5;
    }
    while(cnt2<cnt5){
        if(k*2 <= m){
            k = k*2;
            cnt2++;
        }
        else{
            break;
        }
    }
    while(cnt2>cnt5){
        if(k*5 <= m){
            k = k*5;
            cnt5++;
        }
        else{
            break;
        }
    }
    

    while(k*10 <=m){
        k = k*10;
    }
    // cout<<k<<"test"<<endl;
    if(k==1) cout<<og*m<<endl;
    else{
        ll multi = m/k;
        // cout<<multi<<"test"<<endl;
        k = k* multi;
        // cout<<k<<"trest"<<endl;
        cout<<og*k<<endl;
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