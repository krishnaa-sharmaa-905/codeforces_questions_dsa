#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int power2(int expo){
    int ans =1;
    while(expo--){
        ans = ans*2;
    }
    return ans;
}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> x(q);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<q; i++){
        int num;
        cin>>num;
        // x[i] = pow(float(2),float(num));
        x[i]=num;
        
    }
    int mini = 31;
    for(int i = 0;i<q;i++){
        if(x[i]<mini){
            mini = x[i];
            int num = power2(mini);
            for(int j= 0;j<n;j++){
                if(a[j]%num==0){
                    a[j] = a[j] + (num/2);
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
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