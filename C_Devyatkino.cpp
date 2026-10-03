#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;

    for (int l = 0; l <= 9; l++) { 
        string s = to_string(n - l); 
        int max_digit = 0; 

        
        for (char c : s) {
            if (c <= '7') {
                max_digit = max(max_digit, c - '0');
            }
        }

       
        if (l >= 7 - max_digit) {
            cout << l << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
