#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(int i =  0;i<=n;i++){
            parent[i] = i; 
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u==ulp_v) return;// means they are connected
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int sz = connections.size();
        if(sz<n-1) return -1;
        int extra = 0;
        for(auto it:connections){
            if(ds.findUpar(it[0])==ds.findUpar(it[1])){
                extra++;
            }
            else{
                ds.unionByRank(it[0],it[1]);
            }
        }
        // no of components is calculated as the node whose ultimatre parent are themselves only
        int comp =  0;
        for(int i =  0;i<n;i++){
            if(ds.findUpar(i)==i) comp++;
        }
        int req = comp-1;
        if(extra>=req) return req;
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    int n = 4;
    int ans = sol.makeConnected(n, connections);
    cout<<ans<<endl;
    return 0;
}