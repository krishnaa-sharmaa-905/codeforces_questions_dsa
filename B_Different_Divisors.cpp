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


long long nextPrime(long long num) {
    while (true) {
        if(isPrime(num)){
            return num;
        }
        num++;
        }        
    }

void solve() {
    long long d;
    cin>>d;
    long long second = nextPrime(1+d);
    long long third = nextPrime(second+d);
    long long ans = second*third;
    cout<<ans<<endl;
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