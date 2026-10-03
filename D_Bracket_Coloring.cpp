#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second

#define py cout<<"YES\n";
#define pn cout<<"NO\n";

const ll MOD = 1000000007;

    void solve() {
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<pair<char,int>> st;
        char last = '{';
        if(n%2==1) {
            cout<<"-1"<<endl;
            return;
        }
        int sz = 1;
        int open = count(s.begin(), s.end(), '(');
        if(open != n - open){
            cout << -1 << '\n';
            return;
        }
        vi ans(n);
        int col = 0;
        for(int i = 0; i<n;i++){
            if(st.empty()){
                if(s[i]!= last){
                    if(col == 1){
                        col = 2;
                        sz = 2;
                    }
                    else{
                        col = 1;
                    }
                    last= s[i];
                }
                st.push({last,i});
            }
            else{
                if(s[i] != st.top().ff){
                    ans[i] = col;
                    ans[st.top().ss] = col;
                    st.pop();
                }
                else{
                    
                    st.push({s[i],i});
                }
            }

        }
        if(!st.empty()){
            cout<<"-1"<<endl;
            return;
        }
        else{
            cout<<sz<<endl;
            for(int i  = 0; i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
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