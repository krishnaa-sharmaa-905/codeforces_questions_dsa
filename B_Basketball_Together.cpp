#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


void solve() {
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    ll ans = 0;
    sort(a.begin(),a.end());
    
	int l=-1,r=n-1;
	ll cur = a[r];
	while(l < r){
		
		ll maxp = a[r];
 
		if(cur <= d){
			
			l++;
			cur += maxp;
		}else{
			ans++;
			r--;
 
			if(r>=0) cur = a[r];
		}
	}
 
    cout<<ans<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        solve();
    
    return 0;
}