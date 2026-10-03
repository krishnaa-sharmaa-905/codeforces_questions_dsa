#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> factorial(ll num){
    vector<ll> ans(num+1,1);
    ll multi = 1;
    while(multi<=num){
        ans[multi] = (multi*ans[multi-1])%998244353;
        multi++;
    }
    return ans;
}

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    vector<int> len;
    for(int i = 1;i<n;i++){
        ll curr = 1;
        while(i<n && s[i-1]==s[i]){
            curr++;
            i++;
        }
        if(curr>1){
            len.push_back(curr);
        }
    }

    sort(len.begin(),len.end());
    ll ans = accumulate(len.begin(), len.end(), 0LL);
    ans = ans-(ll)len.size();
    ll sz = len.size();
    if(sz==0){
        cout<<"0"<<" "<<"1"<<endl;
        return;
    }
    vector<ll> facts = factorial(ans);
    ll diff = facts[ans];
    for(int i = 0; i < sz; i++){
        diff = (diff * len[i]) % 998244353;
    }

    cout<<ans<<" "<<diff<<endl;
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