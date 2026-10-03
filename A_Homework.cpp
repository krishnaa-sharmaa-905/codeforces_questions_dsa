#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string a;
    cin>>a;
    int m;
    cin>>m;
    string b;
    cin>>b;
    string c;
    cin>>c;
    for(int i =  0;i<m;i++){
        if(c[i]=='D'){
            a += b[i];
        }
        else{
            a = b[i] + a;
        }
    }
    cout<<a<<endl;
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