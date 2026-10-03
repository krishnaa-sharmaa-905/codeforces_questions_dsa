#include <iostream>
#include <string>
using namespace std;

void solve() {
    int l,r;
    cin>>l>>r;  
    string sl = to_string(l);
    string sr = to_string(r);
    int n = sl.size();
    if(l==r){
        cout<<2*n<<endl;
        return;
    }
    int ans = INT_MAX;
    for(int i = l;i<=r;i++){
        string x  = to_string(i);
        int templ= 0;
        int tempr = 0;
        for(int j= 0;j<n;j++){
            if(sl[j]==x[j]){
                templ++;
            }
            if(sr[j]==x[j]){
                tempr++;
            }
        }
        ans = min(ans,templ+tempr);
        if(ans==0){
            cout<<ans<<endl;
            return;
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