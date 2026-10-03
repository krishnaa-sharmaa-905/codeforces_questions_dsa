#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> divi(int n){
    vector<int> ans;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            if(i != n/i) ans.push_back(n/i);
        }
    }
    return ans;
}

bool isPrime(int num){
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

vector<int> sieve(int n){

    vector<int> ans(n+1);

}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    
    if(gcd(n,a)==1 && gcd(m,b)==1 && gcd(n,m)<=2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}