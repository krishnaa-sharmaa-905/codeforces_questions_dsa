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
        cin >> n;
        
        ll total = 0;
        ll power = 0;
        ll temp = n;
        
        while (temp > 0) {
            ll digit = temp % 3;  
            cnt += digit;
            
            if (digit > 0) {
                ll cnt = pow(3LL, power);
                ll coins;
                if (power == 0) coins = 3; 
                else coins = pow(3LL, power + 1) + power * pow(3LL, power - 1);
                total += digit * coins;
            }
            temp /= 3;
            power++;
        }

        cout << total << endl;
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