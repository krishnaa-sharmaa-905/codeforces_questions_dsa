#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

bool comp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first>b.first;

}

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
    vector<pair<ll, ll>> apair(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> apair[i].first;
        apair[i].second = i + 1;
    }

    
    sort(apair.begin(), apair.end(), comp);

    vector<ll> ans(n + 1, 0);
    ll totalTime = 0;
    ll pos = 1; 

    for (ll i = 0; i < n; i++) {
         
        ans[apair[i].second] = pos;
        totalTime += abs(pos) * apair[i].first;
        pos = -pos; 
        if (pos > 0) pos++; 
    }

    cout << 2 * totalTime << endl;
    for (ll i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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