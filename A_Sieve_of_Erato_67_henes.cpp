#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        st.insert(num);
    }
    if(st.find(67)!=st.end() && st.find(1)!=st.end()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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