#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    long long n;
    cin>>n;
    vector<long long> c(n);
    for(long long i = 0;i<n;i++){
        cin>>c[i];
    }
    sort(c.begin(),c.end());
    if(c[0]!=1){
        cout<<"NO"<<endl;
        return;
    }
    long long sum = c[0];
    for(long long i = 1;i<n;i++){
        if(sum<c[i]){
            cout<<"NO"<<endl;
            return;
        }
        sum +=c[i];
    }
    cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}