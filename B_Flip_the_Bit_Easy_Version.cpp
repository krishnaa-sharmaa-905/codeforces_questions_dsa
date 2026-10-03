#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> special(k);
    for(int i = 0;i<k;i++) cin>>special[i];
    int ans = 0;
    int sp = special[0]-1;
    int all  = a[sp];
    int i = sp;
    int j = sp;
    while(i>=0 || j<n){
        bool flag = false;
        while(i>=0 && a[i]==all){
            i--;
        }
        while(j<n && a[j]==all){
            j++;
        }
        while(i>=0 && a[i]!=all){
            i--;
            flag = true;
        }
        while(j<n && a[j]!=all){
            j++;
            flag = true;
        }
        if(flag){
            ans += 2;
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