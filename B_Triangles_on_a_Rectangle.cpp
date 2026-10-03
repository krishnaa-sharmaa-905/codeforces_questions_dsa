#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

bool isPrime(ll num) {
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

ll maxdiff(vector<int> &num){
    int n = num.size();
    return num[n-1]-num[0];
}

void solve() {

    ll w,h;
    cin>>w>>h;
    int k1;
    cin>>k1;
    vector<int> x0(k1);
    for(int i = 0; i<k1; i++){
        cin>>x0[i];
    }


    int k2;
    cin>>k2;
    vector<int> xh(k2);
    for(int i = 0; i<k2; i++){
        cin>>xh[i];
    }

    int k3;
    cin>>k3;
    vector<int> y0(k3);
    for(int i = 0; i<k3; i++){
        cin>>y0[i];
    }

    int k4;
    cin>>k4;
    vector<int> yw(k4);
    for(int i = 0; i<k4; i++){
        cin>>yw[i];
    }
    ll ansk1 = maxdiff(x0)*h;
    ll ansk2 = maxdiff(xh)*h;
    ll ansk3 = maxdiff(y0)*w;
    ll ansk4 = maxdiff(yw)*w;
    ll ans = max(ansk1,ansk2);
    ans= max(ans,ansk3);
    ans = max(ans,ansk4);
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