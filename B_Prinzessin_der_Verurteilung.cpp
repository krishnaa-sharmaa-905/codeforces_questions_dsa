#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans = "";

    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        if (s.find(c1) == string::npos) {
            ans = c1;
            cout<<ans<<endl;
            return;
        }
    }

    for(char c1 = 'a' ;c1<='z';c1++){
        for(char c2= 'a'; c2<='z';c2++){
            string temp = "";
            temp = temp + c1 + c2;
            if (s.find(temp) == string::npos) {
            ans = temp;
            cout<<ans<<endl;
            return;
            }
        }
    }

    for(char c1 = 'a' ;c1<='z';c1++){
        for(char c2= 'a'; c2<='z';c2++){
            for(char c3 = 'a'; c3<='z'; c3++){
                string temp = "";
                temp = temp + c1 + c2 + c3;
                if (s.find(temp) == string::npos) {
                ans = temp;
                cout<<ans<<endl;
                return;
                }
            }
                
        }
    }

    

    cout << ans << "\n";
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
