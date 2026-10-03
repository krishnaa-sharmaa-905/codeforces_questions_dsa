#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> primes;
void findprime(){
    vector<bool> isPrime(1e6,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2;i<1e6;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i*2;j<1e6;j += i){
                isPrime[j] = false;
            }
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    findprime();
    for(int i = 0;i<n;i++){
        cout<<1LL*primes[i]*primes[i+1]<<" ";
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