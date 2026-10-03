#include <iostream>
#include <vector>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++)cin>>a[i];
    for(int i = 0; i<n; i++)cin>>b[i];
    int diffl = -1;
    int diffr = -1;
    for(int i = 0; i<n; i++){
        if(a[i]!=b[i]){
            diffr = i;
            if(diffl ==-1){
                diffl = i;
            }
        }
    }
    while(diffl>0 && b[diffl-1]<=b[diffl]){
        diffl--;
    }
    while(diffr<n-1 && b[diffr+1]>=b[diffr]){
        diffr++;
    }
    cout<<diffl+1<<" "<<diffr+1<<endl;
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