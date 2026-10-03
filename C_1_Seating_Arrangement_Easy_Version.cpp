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

ll n,x,s;
string seat;
ll help(string& seat, ll m){
    ll n = seat.size();
    ll table = 0;
    ll ans = 0;
    for(ll i = 0;i<n;i++){

        if(seat[i]=='I'){

            if(table==x){
                continue;
            }
            table++;
            // maxtable = min(x,maxtable+1);
            ans++;
        }
        else if(seat[i]=='E'){
            if(ans<table*s) ans++;
        }
        else{
            //seat[i]=='A';
            if(m>0){
                //beahve as intro
                if(table<x){
                    table++;
                    ans++;
                }
            }
            else{
                //behave as extro
                if(ans <table*s) ans++;
            }
            m--;
        }
    }
    return ans;
}

void solve() {
    cin>>n>>x>>s;
    cin>>seat;

    ll l = 0;
    ll r = 0;
    for(ll i = 0;i<n;i++){
        if(seat[i]=='A'){
            r++;
        }
    }

    while(l<r){
        ll m = l + (r-l)/2;

        //m ambi ans intro
        ll temp1 = help(seat,m);
        ll temp2 = help(seat,m+1);

        if(temp1<temp2){
            l = m+1;
        }
        else{
            r = m;
        }

    }
    cout<<help(seat,l)<<endl;

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