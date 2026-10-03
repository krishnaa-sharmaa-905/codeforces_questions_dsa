#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    ll sum = 0;
    for(int i = 0;i<k;i++) sum+=a[i];
    ll total = sum;
    int i = 0 ;
    int j = k;
    while(j<n){
        sum-=a[i];
        sum += a[j];
        total += sum;
        i++;
        j++;
    }
    double div = (double)n-k+1;
    double ans = (double)total;
    ans = ans/div;
    cout<<fixed<<setprecision(6)<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}