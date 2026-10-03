#include <iostream>
#include <vector>
using namespace std;

void print(int ans){
    if(ans==0){
        cout<<"Tie"<<endl;
    }
    else if(ans==1){
        cout<<"Ajisai"<<endl;
    }
    else if(ans==2){
        cout<<"Mai"<<endl;
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    int allxor = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        allxor ^= a[i];
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
        allxor ^= b[i];
    }
    if(allxor==0){
        print(0);
        return;
    }
     int bit = -1;
    for (int i = 0; i < 20; i++) {
        if (allxor & (1 << i)) {
            bit = i;
        }
    }

    
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if ((a[i] ^ b[i]) & (1 << bit)) {
            idx = i;
        }
    }
    if (idx % 2 == 0) {
        print(1);
    } else {
        print(2);
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