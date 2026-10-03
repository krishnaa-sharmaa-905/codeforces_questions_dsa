#include <iostream>
#include <string>
using namespace std;

void solve() {
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    int maxlen = 0;
    for(int i=0;i<n;i++){
        for(int j = 0; j<m; j++){
            int len = 0;
            while(j+len<m && i+len<n ){
                if(a[i+len]==b[j+len]){
                    len++;
                }
                else{
                    break;
                }

            }
            maxlen = max(len,maxlen);
        }

    }
    int ans = n+m-(2*maxlen);
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