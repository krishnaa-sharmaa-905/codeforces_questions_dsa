#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    long long n,s,x;
    cin>>n>>s>>x;
    long long sum = 0;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum +=a[i];
    }
    if(sum>s){
        cout<<"NO"<<endl;
    }
    else{
        long long temp = s-sum;
        if(temp%x==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
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