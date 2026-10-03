#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=  "1" + s + "1"; 
    int start = 0;
    int i = 1;
    int ans = 0;
    while(i<=n){
        if(s[i]=='0'){
            if(s[i-1] =='1'){
                start = i;
            }
            if(s[i+1]=='1'){
                int conzero = i-start+1;
                if(start==1){
                    conzero +=1; 
                }
                if(i==n){
                    conzero++;
                }
                ans += conzero/3;
            }
        }
        else{
            ans++;
        }
        i++;
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