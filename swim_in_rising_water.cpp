#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<pair<int,pair<int,int>>> temp;
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back({grid[i][j],{i,j}});
            }
        }
        sort(temp.begin(), temp.end());
        DSU dsu(n*n);
        vector<vector<int>> vis(n, vector<int>(n,0));
        for(int i  =0;i<n*n;i++){
            int ht = temp[i].first;
            int r = temp[i].second.first;
            int c = temp[i].second.second;
            vis[r][c] = 1;
            int delr[4] = {-1,0,1,0};
            int delc[4] = {0,1,0,-1};
            for(int j=0;j<4;j++){
                int nrow = r + delr[j];
                int ncol = c + delc[j];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==1){
                    dsu.unionByRank(r*n+c, nrow*n+ncol);
                }
            }
            if(dsu.findUPar(0) == dsu.findUPar(n*n-1)) return ht;
        }
        return -1;
        
    }
};

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(int a, int b) {
    return (1LL * a / gcd(a, b)) * b;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}