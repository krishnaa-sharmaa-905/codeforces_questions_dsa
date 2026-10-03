#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    int l = -1;
    int r = -1;
    int num = -1;
    for(int i = 0; i<n; i++){
        if(a[i]!=n-i && l==-1){
            l = i;
            num = n-i;
        }
        if(l!=-1 && a[i]==num){
            r = i;
            break;
        }
    }
    // cout<<l<<" "<<r;
    if(l==-1 && r==-1){
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    reverse(a.begin()+l, a.begin()+r+1);
    for(auto it:a){
            cout<<it<<" ";
        }
    cout<<endl;
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