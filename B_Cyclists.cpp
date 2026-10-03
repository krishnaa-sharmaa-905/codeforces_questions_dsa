
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    deque<pair<int,int>> dq;
    for(int i=0;i<n;i++){
        dq.push_back({a[i],i==p-1});
    }
    int e=m;
    int ans=0;
    while(true){
        int pos=-1;
        for(int i=0;i<k && i<dq.size();i++){//if in top k
            if(dq[i].second){
                pos=i;
                break;
            }
        }
        if(pos==-1){//not in top k
            // find the minimum out of k and take its position to remove it
            int mn=1e9;
            for(int i=0;i<k && i<dq.size();i++){
                if(dq[i].first<mn){
                    mn=dq[i].first;
                    pos=i;
                }
            }
        }
        if(dq[pos].first>e) break;// cost <m
        e-=dq[pos].first;
        auto c=dq[pos];
        dq.erase(dq.begin()+pos);
        dq.push_back(c);// push back agin at end
        if(c.second) ans++;// win card
    }
    cout<<ans<<"\n";
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}