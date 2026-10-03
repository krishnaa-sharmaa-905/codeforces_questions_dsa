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

ll odd(ll a){
    while(a%2==0){
        a=a/2;
    }
    return a;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a > b) swap(a, b); 

    if (odd(a) != odd(b)) {
        cout << "-1"<<endl; 
        return;
    }

    int ans = 0;
    ll ratio = b / a;

    while (ratio >= 8) {
        ratio /= 8;
        ans++;
    }
    if (ratio > 1) ans++;

    cout << ans << endl;
    
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