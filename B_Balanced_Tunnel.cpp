#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    queue<int> q;
    for(int i =  0;i<n;i++){
        cin>>a[i];
        q.push(a[i]);
    } 
    for(int i = 0; i<n; i++) cin>>b[i];
    set<int> st;
    int ans = 0;
    for(int i =  0;i<n;i++){
        while(!q.empty() && st.find(q.front())!=st.end()){
            q.pop();
            // continue;
        }
        int curr = q.front();
        if(curr!=b[i]){
            st.insert(b[i]);
            ans++;
            // q.pop();
        }
        else{
            q.pop();
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    solve();
    return 0;
}