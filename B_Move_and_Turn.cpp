#include <iostream>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int ans = 0;
    if(n%2==0){
        int k = n/2;
        ans = (k+1)*(k+1);
    }
    else{
        int k = n/2;
        ans = 2*(k+1)*(k+2);
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}