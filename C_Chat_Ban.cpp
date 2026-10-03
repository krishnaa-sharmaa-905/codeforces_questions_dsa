#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll firsthalf(ll x,ll k){
    ll low = 1;
    ll high = k;
    ll ans = 0;
    while(low<=high){
        ll mid = low + (high-low)/2;
        ll uptom =0; 
        if(mid%2==0){
            uptom = mid/2;
            uptom = uptom*(mid+1);
        }
        else{
            uptom = (mid+1)/2;
            uptom = uptom*(mid);
        }
        if(uptom<x){
            low = mid +1 ;
        }
        else if(uptom>=x){
            high = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

ll secondhalf(ll x,ll k,ll uptok){

    ll low = 1;
    ll high = k-1;
    ll ans = k-1;
    while(low<=high){
        ll mid = low + (high-low)/2;
        ll uptom =0; 
        if(mid%2==0){
            uptom = mid/2;
            uptom = uptom*(2*k-mid-1);
        }
        else{
            uptom = (2*k-mid-1)/2;
            uptom = uptom*(mid);
        }
        uptom += uptok;

        if(uptom<x){
            low = mid +1 ;
        }
        else if(uptom>=x){
            high = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

void solve() {
    ll k,x;
    cin>>k>>x;
    if(k==1 || x==1){ cout<<"1"<<endl;return;}
    ll uptok = 0;
    if(k%2==0){
        uptok = k/2;
        uptok = uptok*(k+1);
    }
    else{
        uptok = (k+1)/2;
        uptok = uptok*(k);
    }
    ll ans = 0;
    if(uptok==x){ cout<<k<<endl; return;}
    
    if(uptok>x){//answer will be less than k
        // first half + ans
        ans += firsthalf(x,k);
    }
    else if(uptok<x){//answer will be more than k
        ans +=k;
        // second half
        ans += secondhalf(x,k,uptok);
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