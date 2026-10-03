#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(i%2==0){
            a[i] = a[i]*-1;
        }
    }
    set<long long> st;
    long long sum = 0;
    for(int i =0;i<n;i++){
        sum += a[i];
        if(sum==0 || st.find(sum)!=st.end()){
            cout<<"YES"<<endl;
            return;
        }
        st.insert(sum);
    }
    cout<<"NO"<<endl;
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