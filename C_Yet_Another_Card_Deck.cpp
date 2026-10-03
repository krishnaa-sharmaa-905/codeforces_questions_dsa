#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

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
    ll n;
    ll q;
    cin>>n;
    cin>>q;
    vector<int> a(n);
    vector<int> t(q);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<q; i++){
        cin>>t[i];
    }
    vector<int> card(51,-1);
    for(int i = 0;i<n;i++){
        if(card[a[i]]==-1){
            card[a[i]] = i+1;
        }
        
    }
    vector<int> ans;
    it op =0;
    for(int i = 0;i<q;i++){
        int temp  = t[i];
        // ans.push_back(temp);
        // t[i] = 1;
        
        
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
        solve();
    
    return 0;
}