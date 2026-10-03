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
    vector<ll> ans;
    ll p = 1;
    for(int i = 0;i<=18;i++){
        p *= 10;
        ll x = p;
        x++;
        if(x > n) break;
        if(n%x == 0) {
            ans.push_back(n/x);
        }
    }
    if(ans.size() == 0) {
        cout << 0 << endl;
    } else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
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