#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n == 1) {
        cout << "no" << endl;
        return;
    }

    string revs = s;
    reverse(revs.begin(), revs.end());

    
    if (s < revs) {
        cout << "yes" << endl;
        return;
    }

    
    if (s == revs) {
    
        bool allsame = true;
        for (char c : s) {
            if (c != s[0]) {
                allsame = false;
                break;
            }
        }

        if (allsame) {
            cout << "no" << endl;
        } else {
            if (k > 0) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
            
        }
        return;
    }

    
    if (k > 0) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
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
