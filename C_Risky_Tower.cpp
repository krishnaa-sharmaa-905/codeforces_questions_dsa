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

bool comp(ll a, ll b) {
    return a > b;
}

vll merge(vll &cur, vll &row, int m) {

    vll temp;
    int p1 = 0;
    int p2 = 0;

    while ((int)temp.size() < m && (p1 < (int)cur.size() || p2 < m)) {
        if (p1 < (int)cur.size() && (p2 == m || cur[p1] >= row[p2])) {

            temp.pb(cur[p1]);
            p1++;

        }
        else {
            temp.pb(row[p2]);
            p2++;
        }
    }

    return temp;
}

int mini(vll &cur, ll need) {

    ll sum = 0;
    for (int i = 0; i < (int)cur.size(); i++) {
        sum += cur[i];
        if (sum >= need){
            return i + 1;
        }
    }

    return INT_MAX;
}

void solve() {
    int n,m;
    cin>>n>>m;

    vll v(n);
    for(int i = 0;i<n;i++) cin>>v[i];

    vector<vll> a(n,vll(m));
    for(int i = 0; i<n; i++){
        for(int j =  0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans = m;
    vll curr;

    for(int i = n-1;i>=0;i--){
        sort(a[i].begin(),a[i].end(),comp);
        curr = merge(curr,a[i],m);
        ans = min(ans,mini(curr,v[i]));

        if(ans==1) break;
    }

    cout<<ans<<endl;

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