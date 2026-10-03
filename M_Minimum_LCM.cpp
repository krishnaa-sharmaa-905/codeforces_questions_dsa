#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true; 
    if (num % 2 == 0 || num % 3 == 0) return false; 
    
    for (int i = 5; i * i <= num; i += 6) { // Check only numbers of form 6k ± 1
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

void solve(){
    int n;
    cin>>n;
   

    int a = 1, b = n - 1; 
    int minLCM = lcm(a, b);

    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int curra = i, currb = n - i;
            int currLCM = lcm(curra, currb);
            if (currLCM < minLCM) {
                a = curra;
                b = currb;
                minLCM = currLCM;
            }

            
            curra = n / i;
            currb = n - curra;
            currLCM = lcm(curra, currb);
            if (currLCM < minLCM) {
                a = curra;
                b = currb;
                minLCM = currLCM;
            }
        }
    }

    cout << a << " " << b << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}