#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
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
    cin>>n;
    ll lower = n;
    ll higher = ((n + 2519) / 2520) * 2520;
    ll ans =0;
    for(ll i = n; i<=higher; i++){
        ll temp = i;
        
        vector<bool> yesno(10,false);
        while(temp){
            int digit = temp%10;
            
            yesno[digit]=true;
            temp = temp/10;
        }
        bool check = true;
        for(int j = 2; j<=9; j++){
            if(yesno[j]==true){
                if(i%j!=0){
                    check = false;
                    break;
                }
            }

        }
        if(check==true){
            ans = i;
            break;
        }
    }
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