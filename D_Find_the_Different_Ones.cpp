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
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    int q;
    cin>>q;
    vector<vector<int>> queries(q,vector<int>(2));
    for(int i = 0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    vector<int> diff(n);
    diff[0] = -1;
    for(int i= 1;i<n;i++){
        if(a[i-1]!=a[i]){
            diff[i] = i-1;
        }
        else{
            diff[i] = diff[i-1];
        }
    }

    for(int i =  0;i<q;i++){
        int l = queries[i][0]-1;
        int r = queries[i][1]-1;
        if(diff[l]==diff[r]){
            cout<<-1<<" "<<-1<<endl;
            continue;
        }
        if(a[l]!=a[r]){
            cout<<l+1<<" "<<r+1<<endl;
            continue;
        }
        else{
            cout<<l+1<<" "<<diff[r]+1<<endl;
            continue; 
        }
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