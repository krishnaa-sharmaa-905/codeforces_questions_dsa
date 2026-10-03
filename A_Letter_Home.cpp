#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int s;
    cin>>s;
    vector<int> a(n);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mini = min(a[i],mini);
        maxi = max(a[i],maxi);
    }
    int ans= 0;
    if(s>=mini && s<=maxi){
        int diffmin = min(abs(maxi-s),abs(mini-s));
        int diffmax = max(abs(maxi-s),abs(mini-s));
        ans = diffmin*2 + diffmax;
    }
    else if(s>maxi){
        ans = abs(mini-s);
    }
    else if(s<mini){
        ans = abs(maxi-s);
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