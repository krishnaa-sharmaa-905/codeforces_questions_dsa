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

void solve() {
    int n;
    cin>>n;
    if(isPrime(n)){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> factors;
    for(int i = 2; i*i <=n; i++){
        if(n%i !=0) continue;
        factors.push_back(i);
        n = n/i;
        if(factors.size()==2){
            break;
        }
    }
    if(n==1 || factors.size()<2 || n==factors[0] || n== factors[1]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<factors[0]<<" "<<factors[1]<<" "<<n<<endl;
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