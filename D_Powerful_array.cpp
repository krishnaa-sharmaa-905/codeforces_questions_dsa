#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second

#define py cout<<"YES\n";
#define pn cout<<"NO\n";

const ll MOD = 1000000007;



struct Query{
    ll l, r, ind;
};

ll BLOCK;

bool comp(Query& a, Query& b){

    ll blocka = a.l / BLOCK;
    ll blockb = b.l / BLOCK;

    if(blocka != blockb)
        return blocka < blockb;

    if(blocka & 1)
        return a.r > b.r;

    return a.r < b.r;
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vi a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    vector<Query> v(q);
    for(ll i=  0;i<q;i++){
        cin>>v[i].l>>v[i].r;
        v[i].l--;
        v[i].r--;
        v[i].ind = i;
    }
    BLOCK = sqrt(n);
    vector<ll> ans(q);
    vector<ll> freq(1e6+1,0);
    sort(v.begin(),v.end(),comp);

    ll sum = 0;
    ll currl = 0;
    ll currr = -1;
    for(ll i = 0;i<q;i++){
        ll L = v[i].l;
        ll R = v[i].r;
        ll currind = v[i].ind;
        //expland l
        
        //expand r
        //shrink l
        //shrink r
        while(currl < L){
            ll x = a[currl];
            sum -= 1LL * x * freq[x] * freq[x];
            freq[x]--;
            sum += 1LL * x * freq[x] * freq[x];
            currl++;
        }

        while(currl > L){
            currl--;
            ll x = a[currl];
            sum -= 1LL * x * freq[x] * freq[x];
            freq[x]++;
            sum += 1LL * x * freq[x] * freq[x];
            }

        while(currr < R){
            currr++;
            ll x = a[currr];
            sum -= 1LL * x * freq[x] * freq[x];
            freq[x]++;
            sum += 1LL * x * freq[x] * freq[x];
        }

        while(currr > R){
            ll x = a[currr];
            sum -= 1LL * x * freq[x] * freq[x];
            freq[x]--;
            sum += 1LL * x * freq[x] * freq[x];
            currr--;
        }

        ans[currind] = sum ;
    }
    for(ll i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}