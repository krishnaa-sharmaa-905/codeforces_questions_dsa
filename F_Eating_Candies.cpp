#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    vector<int> w(n);
    for(int i = 0; i<n; i++){
        cin>>w[i];
    }
    vector<ll> prel(n);
    vector<ll> prer(n);
    prel[0] = w[0];
    prer[n-1] = w[n-1]; 
    //prel calculation
    for(int i = 1; i<n; i++){
        prel[i] = prel[i-1]+w[i];
    }
    //prer calculation
    for(int i = n-2; i>=0; i--){
        prer[i] = prer[i+1]+ w[i];
    }
    // cout<<"test->prer"<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<<prer[i]<<" ";
    // }
    // cout<<endl;
    int l = 0;
    int r =n-1;
    int ans = 0;
    while(r>l){
        if(prel[l]>prer[r]){
            r--;
        }
        else if(prel[l]<prer[r]){
            l++;
        }
        else{
            l++;
            r--;
            ans = (n-r-1) + (l);
        }
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