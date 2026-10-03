#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;



void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    ll y  = 2*a[0]-a[1];
    y = y/(n+1);
    ll x= a[1]-a[0]+y;
    if(y < 0 || x < 0) {
        cout << "NO" << endl;
        return;
    } 
    
    for(int i = 0; i<n; i++){
        a[i] -= x*(i+1) ;
        a[i]-=  y*(n-i);
        
    }
    for(int i = 0; i<n; i++){
        if(a[i]!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

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