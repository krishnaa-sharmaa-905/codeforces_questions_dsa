#include <iostream>

using namespace std;



void solve() {
    int k;
    cin>>k;
    if(k%2==0){
        cout<<"NO"<<endl;

    }
    else{
        cout<<"YES"<<endl;
    }
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