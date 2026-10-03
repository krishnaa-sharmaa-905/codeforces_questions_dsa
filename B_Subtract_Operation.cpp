#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l = 0;
    int r = 1;
    while(r<n){
        
        if(a[r]-a[l]==abs(k)){
            cout<<"YES"<<endl;
            return;
        }
        else if(a[r]-a[l]>abs(k)){
            l++;
        }
        else{
            r++;
        }
         
    }
    cout<<"NO"<<endl;
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