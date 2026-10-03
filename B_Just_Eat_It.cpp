#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(vector<ll>& nums, int l,int r){
    int n = nums.size();
    ll sum = 0;
    ll ans = 0;
    for(int i = l;i<=r;i++){
        sum += nums[i];
        if(sum>ans){
            ans = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    ll adele = max(kadane(a,0,n-2),kadane(a,1,n-1));
    // ll sum = a[0];   
    // ll currstart = 0;
    // ll resstart = 0;
    // ll resend = 0;
    ll totalsum = 1LL*accumulate(a.begin(),a.end(),0*1LL);
    // for(ll i = 1; i<n; i++){
    //     if(sum + a[i] < a[i]){
    //         currstart = i;
    //         sum = a[i];
    //     }
    //     else{
    //         sum += a[i];
    //     }
    //     if(sum>adele){
    //         adele = sum;
    //         resstart = currstart;
    //         resend = i;
    //     }
    //     if(adele>=totalsum) break;
    // }
    // if(resstart == 0 && resend == n-1){
    //     cout<<"YES"<<endl;
    //     return;
    // }
    vvovooovovvovoovoovvvvovovvvov

    if(adele>=totalsum){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
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