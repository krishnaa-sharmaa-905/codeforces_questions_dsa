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

void solve() {
    string a;
    int n;
    cin>>a>>n;
    vi d(n);
    for(int i = 0; i<n; i++)cin>>d[i];
    string b1 = "";//b1>a
    string b2 = "";//b2<a

    //making of b1
    bool flagadd = false;
    for(int i = 0;i<a.size();i++){
        
        int digita = a[i]-'0';
        int ind = lower_bound(d.begin(),d.end(),digita) - d.begin();
        if(ind <n){
            b1 = b1 + char(d[ind]+'0');
        }
        else{//greater than digita not exist in d
            flagadd = true;
            b1 = b1 + char(d[0]+'0') ;
        }
    }
    if(flagadd) b1 = b1 + char(d[0]+'0');
    // cout<<b1<<endl; 

    //making of b2
    bool flagremove = false;
    for(int i = 0;i<a.size();i++){
        int digita = a[i]-'0';
        int ind = lower_bound(d.begin(),d.end(),digita) - d.begin();
        if(ind<n){
            b2 = b2 + char(d[min(n-1,ind+1)] + '0');
        }
        else{
            flagremove = true;
            b2 = b2 + char(d[n-1] + '0');
        }
    }
    if(b2>a){
        b2.erase(b2.size()-1);
    }
    if(b2.size()==0){
        b2 = "0";
    }
    // cout<<b2<<endl;
    ll numa = stoll(a);
    ll numb1 = stoll(b1);
    ll numb2 = stoll(b2);
    ll ans = 1LL*min(numb1 - numa, numa - numb2);
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