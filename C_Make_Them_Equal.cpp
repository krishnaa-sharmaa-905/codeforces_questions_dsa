#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    char c;
    cin>>c;
    string s;
    cin>>s;
    vector<int> diff;
    for(int i = 0 ;i< n ;i++){
        if(s[i]!= c){
            diff.push_back(i);
        }
    }
    int sz = diff.size();
    if(sz==0){
        cout<<"0"<<endl;
        return;
    }
    for(int i = 2; i<=n; i++){
        bool flag = true; 
        for(int j = i;j<=n;j +=i){
            if(s[j-1]!=c){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"1"<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<"2"<<endl;
    cout<<n-1<<" "<<n<<endl;
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