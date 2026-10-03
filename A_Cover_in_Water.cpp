#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string temp = "...";
    
    for(int i= 0;i<n-2;i++){
        string sub = s.substr(i,3);
        if(sub==temp){
            cout<<"2"<<endl;
            return;
        }
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='.'){
            cnt++;
        }
    }
    cout<<cnt<<endl;

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