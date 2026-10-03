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

vi help(int mul1,int mul2,unordered_map<int,pii>& mpp,vi& og){
    pii p1 = mpp[mul1];
    pii p2 = mpp[mul2];

    int a = p1.first;
    int b = p1.second;
    int c = p2.first;
    int d = p2.second;

    vi ans(3);

    if(a == c){
        ans = {b,a,d};
    }
    else if(a == d){
        ans = {b,a,c};
    }
    else if(b == c){
        ans = {a,b,d};
    }
    else{
        ans = {a,b,c}; // b == d
    }

    return ans;
}

void solve() {
    vi og{4, 8, 15, 16, 23, 42};
    vi ans;
    unordered_map<int,pii> mpp;
    for(int i =0 ;i<6;i++){
        int num = og[i];
        for(int j = 0;j<6;j++){
            if(i==j) continue;
                mpp[num*og[j]]={og[i],og[j]};
        }
    }
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    int mul1;
    cin>>mul1;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    int mul2;
    cin>>mul2;
    cout<<"? 4 5"<<endl;
    fflush(stdout);
    int mul3;
    cin>>mul3;
    cout<<"? 5 6"<<endl;
    fflush(stdout);
    int mul4;
    cin>>mul4;

    vi temp1 = help(mul1,mul2,mpp,og);
    for(int i =  0;i<3;i++){
        ans.pb(temp1[i]);
    }
    temp1 =  help(mul3,mul4,mpp,og);
    for(int i =  0;i<3;i++){
        ans.pb(temp1[i]);
    }

    cout<<"! ";
    for(int i = 0;i<6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}