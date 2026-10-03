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
    if(n%2==0){
        for(int i = 1;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" "<<i<<" "<<i+1<<" "<<i+1<<" "<<i<<" "<<i+1<<" "<<i<<" "; 
        }
        cout<<endl;
        return;
    }
    else{
        cout<<"1 1 2 1 2 3 1 3 2 2 3 3 ";
        for(int i =4;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" "<<i<<" "<<i+1<<" "<<i+1<<" "<<i<<" "<<i+1<<" "<<i<<" ";
        }
        cout<<endl;
        return ;
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