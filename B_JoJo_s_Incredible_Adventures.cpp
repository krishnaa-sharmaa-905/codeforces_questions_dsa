#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max1(string &s){    
    ll cnt = 0;
    ll n = s.size();
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    return max(ans,cnt);
}
void solve() {
    string s;
    cin>>s;
    ll n= s.size();
    ll ans = 0;
    ll multi =1;
    ll x = max1(s);
    ll start_end0 = 0;
    ll l = 0;
    ll r = n-1;
    if(s[l]== '1'  && s[n-1]=='1'){
        while(l<n && s[l]=='1'){
            start_end0++;
            l++;
            
        }
        while(r>l && s[r]=='1'){
            start_end0++;
            r--;

        }
    }
    x= max(x,start_end0);
    if(x==n){
       ans = n*n;
    }
    else{
        ll sidea = (x+1)/2;
        ll sideb = (x+2)/2;
        ans = sidea*sideb;
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