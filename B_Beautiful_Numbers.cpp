#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    if(n==1){
        cout<<"0"<<endl;
        return;
    }
    string temp = s.substr(1);
    temp.push_back(s[0]-1);
    sort(temp.begin(),temp.end());
    // cout<<temp<<endl;
    int ans =0;
    int sum = 0;
    for(char c : s){
        sum += c - '0';
    }
    int i=  n-1;
    while(i>=0 && sum>9){
        sum-= (temp[i]-'0');
        ans++;
        i--;
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