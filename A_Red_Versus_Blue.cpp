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
    int n,r,b;
    cin>>n>>r>>b;
    int beff = b+1;
    int eachr = r/beff;
    int extrar = r%beff;
    vector<char> ans(n);
    bool red = true;
    int temp =eachr;
    for(int i = 0; i<n; i++){
        if(red){
            if(temp>0){
                ans[i]='R';
                temp--;
            }
            if(temp<=0){
                if(extrar>0){
                    ans[i+1]='R';
                    extrar--;
                    i=i+1;
                }
                red = false;
                temp = eachr;
            }

        }
        else{
            ans[i]='B';
            red = true;
        }
    }  
    for(int i = 0; i<n; i++){
        cout<<ans[i];
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