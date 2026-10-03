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
    vi a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> s1(n),s2(n);
    if(a[0]==1){
        s1[0] = 1;
    }
    else{
        s1[0] = -1;
    }

    if(a[0]<=2){
        s2[0] = 1;
    }
    else{
        s2[0] = -1;
    }

    
    for(int i  =1 ;i<n;i++){
        if(a[i] ==1){
            s1[i] = s1[i-1] + 1;
        }        
        else{
            s1[i] = s1[i-1] - 1;
        }

        if(a[i] <=2){
            s2[i] = s2[i-1] + 1;
        }        
        else{
            s2[i] = s2[i-1] - 1;
        }
    }
    bool ans = false;
    int mini = INT_MAX;
    for(int i =  0;i<n-2;i++){
        if(s1[i]>=0){
            if(s2[i]<mini){
                mini = s2[i];
            }
        }
        if(s2[i+1]>=mini){
            ans = true;
            break;
        }

    }
    if(ans){
        py;
    }
    else{
        pn;
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