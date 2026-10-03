#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


void primeFactors(int n, map<int,int>& mpp) {
    while (n % 2 == 0) {
        mpp[2]++;
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }

    if (n > 2) {
        mpp[n]++;
    }
}
  
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        primeFactors(a[i], mpp);
    } 
    for(auto it:mpp){
        if(it.second%n!=0){
            // cout<<it.second<<" ";
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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