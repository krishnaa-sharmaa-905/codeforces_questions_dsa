#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(int a, int b) {
    return (1LL * a / gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = n-1; i>=0 ;i-- ){
        if(i==n-1 && b[i]!= a[i]) {
            // cout << "NO" << endl;
            return;
        }
        if(a[i]==b[i]){
            continue;
        }
        if(b[i] == a[i] ^ a[i+1]){
            a[i] = a[i] ^ a[i+1];
        } else {
            // cout << "NO" << endl;
            return;
        }
        
    }
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<b[i]<<" ";
    }
    // if(a[0]!=b[0]){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    
    cout<<"YES" << endl;
        return;
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