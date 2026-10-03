#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<int> a(n);
    ll negno = 0;
    ll negind = 0;
    ll sum = 0;
    bool negfound = false;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum +=abs(a[i]);
        if(a[i]<0){
            negno++;
            if(negfound==false){
                negind = i;
                negfound = true;
            }
        }
    }
    int mini = INT_MAX;
    for(int i = 0;i<n;i++){
        mini = min(mini,abs(a[i]));
        negind++; 
    }
    ll ans = 0; 
    if(negno&1){
        ans = sum - (2*mini);
    }
    else{
        ans = sum;
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