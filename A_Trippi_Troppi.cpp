#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s1 = "";
    
    for(int i=0;i<3;i++){
        string s;
        cin>>s;
        s1 += s[0];
    }
    cout<<s1<<endl;
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