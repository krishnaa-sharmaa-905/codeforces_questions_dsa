#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int close = 0;
    int open = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='('){
            open++;
        }
        else{
            close++;
        }
        if(close>open){
            ans++;
            close--;
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