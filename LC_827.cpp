#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.resize(n+1, 1);
    }
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        map<pair<int,int>, int> zermpp;
        for(int i =  0;i<n;i++){
            for(int j = 0 ;j<n;j++){
                if(grid[i][j]==0) {
                    zermpp[{i,j}] = 0;
                    continue;
                }
                else{
                    int node = i*n+j;
                    for(auto dir:directions){
                        int newr = i + dir[0];
                        int newc = j + dir[1];
                        if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                            int adjNode = newr*n+newc;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }    
            int ans =0;
            for(auto it:zermpp){
                int currnode = it.first.first*n + it.first.second;
                unordered_set<int> comp;  
                for(auto dir:directions){
                    int newr = it.first.first + dir[0];
                    int newc = it.first.second + dir[1];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int adjnode = newr*n+newc;
                        comp.insert(ds.findUPar(adjnode));
                    }
                }
            
            int maxi = 0;
            for(auto it: comp){
                maxi += ds.size[it];
            }
            ans = max(ans,maxi+1);
            }
        for(int i = 0;i<n*n;i++){
        ans = max(ans,ds.size[ds.findUPar(i)]);
        }
    return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> grid1 = {{1,0},{0,1}};
    vector<vector<int>> grid2 = {{1,1},{1,0}};
    vector<vector<int>> grid3 = {{1,1},{1,1}};
    Solution sol;
    cout<<sol.largestIsland(grid1)<<endl;
    cout<<sol.largestIsland(grid2)<<endl;
    cout<<sol.largestIsland(grid3)<<endl;
    return 0;
}