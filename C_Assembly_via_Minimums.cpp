#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int m = (n*(n-1))/2;
    vector<int> b(m);
    for(int i = 0; i<m; i++) cin>>b[i];
    sort(b.begin(),b.end());
    vector<int> a(n);
    int idx = 0;
    int temp = n ;
    for(int i = 0; i<m; i += temp) {
        // cout<<temp<<" ";
        a[idx++] = b[i];
        temp--;
    }
    // cout<<endl;
    a[n-1] = 1000000000;

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