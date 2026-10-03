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
    cin>>n;
    vector<ll> a(n);
    vector<ll> nums(n);
    map<ll,ll> mpp;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        nums[i] = a[i] - i;
        if(mpp.find(nums[i])!=mpp.end()){
            mpp[nums[i]]++;
        }
        else{
            mpp[nums[i]] = 1;
        }
    }
    ll ans = 0;
    for(auto it:mpp){
        ll cnt = it.second;
        if(cnt>1){
            if(cnt%2==0){
                ans += ((cnt/2) *(cnt-1)); 
            }
            else{
                ans += (((cnt-1)/2) *(cnt)); 
            }
        }
    }
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