#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ans = INT_MAX;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        ans = min(ans,abs(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}