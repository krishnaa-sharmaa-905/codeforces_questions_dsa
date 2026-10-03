#include <iostream>
#include <string>
using namespace std;



void solve() {
    string s;
    cin>>s;
    int n = s.size();
    int r = n-1;
    int l = 0;
    int ans = 0;
    while(r>=0){
        if(s[r]=='0'){
            r--;
            ans++;
        }
        else{
            break;
        }
    }
    while(r>l){
        if(s[l]!='0'){
            ans++;
            l++;
        }
        else{
            l++;
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