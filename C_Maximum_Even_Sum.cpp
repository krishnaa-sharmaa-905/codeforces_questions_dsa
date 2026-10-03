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
    ll a, b;
    cin >> a >> b;

    if (b % 2 == 1) { // b is odd
        if (a % 2 == 1) {
            cout << a * b + 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    
    if ((a % 2 == 1) && (b % 4 != 0)) {
        cout << -1 << "\n";
        return;
    }

    
    ll ans1 = 0;
    if(a%2==1){
        ans1 = a * 2 + (b / 2);
    }
    else{
        ans1 = a  + b;
    }
    ll ans2 = a * (b / 2) + 2;

    cout << max(ans1, ans2) << "\n";
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