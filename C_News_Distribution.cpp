#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>


void print(vector<int>&a){
    for(int i = 0 ;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

class Disjoint{
    public:
    vector<int> parent,rank;

    Disjoint(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i  = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int U_Par(int node){
        if(parent[node]==node) return node;

        return parent[node] = U_Par(parent[node]);
    }

    void Union(int u, int v){
        int ulpv = U_Par(v);
        int ulpu = U_Par(u);
        if(ulpu==ulpv) return;

        if(rank[ulpu]>rank[ulpv]){
            parent[ulpv] = ulpu;
        }
        else if(rank[ulpv]>rank[ulpu]){
            parent[ulpu] = ulpv;
        }
        else{
            parent[ulpu] = ulpv;
            rank[ulpv]++;
        }
    }
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vi> edges;
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        if(k==0) continue; 
        vector<int> temp(k);
        for(int j = 0;j<k;j++){
            cin>>temp[j];
            temp[j]-=1;
        }
        edges.pb(temp);
    }
    vector<vi> adj(n);
    for(int i=  0;i<edges.size();i++){
        vi temp = edges[i];
        int u = temp[0];
        for(int j=  1;j<temp.size();j++){
            int v = temp[j];
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    Disjoint ds(n);
    for(int i = 0;i<n;i++){
        int u = i;
        for(auto it:adj[u]){
            ds.Union(u,it);
        }
    }
    vector<int> cnt(n);
    // vi par = ds.parent;
    for(int i = 0;i<n;i++){
        cnt[ds.U_Par(i)]++;
    }
    vi ans(n);
    for(int i = 0;i<n;i++){
        int ulp = ds.U_Par(i);
        ans[i] = cnt[ulp];
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}