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
    int n,k;
    cin>>n>>k;
    vector<char> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int i = 0;
    int j= 0;
    int ans = INT_MAX;
    int change = 0;
    while(j<n ){
        
        int currlen = j-i+1;
        if (arr[j] == 'W') {
            change++;  
        }


        if(currlen==k){
            ans = min(ans,change);
            if (arr[i] == 'W') {
                change--;  
            }
            
            i++;
           
            
        }
        j++;
        
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