#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int cnt0 = 0;
    int cnt1 = 0;
    vector<bool> change(n,false);
    for(int i = 0;i<n;i++){
        if(a[i]=='0')cnt0++;
        else {
            cnt1++;
        }
        if(cnt0==cnt1) change[i] = true; 
    }
    bool ans = true;
    bool flipped = false;
    for(int i = n-1; i>=0; i--){
        if(flipped == false){
            if(a[i]!=b[i]){
                if(change[i]==true){
                    flipped = !flipped;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        else{
            if(a[i]==b[i]){
                if(change[i]==true){
                    flipped = !flipped;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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