#include <bits/stdc++.h>
using namespace std;
int delrow[4] = {1,0,-1,0};
int delcol[4] = {0,-1,0,1};
vector<vector<char>> grid;
int n,m;

bool valid(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m && grid[i][j]!='#'){
        return true;
    }
    return false;
}

void solve() {
    cin>>n>>m;
    grid.assign(n,vector<char>(m));
    int srow = -1;
    int scol = -1;
    int erow = -1;
    int ecol = -1;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='S'){
                srow = i;
                scol = j;
            }
            if(grid[i][j]=='T'){
                erow = i;
                ecol = j;
            }
        }
    }
    bool vis[n][m][4][4] = {0};
    queue<vector<int>> q;
    for(int i = 0;i<4;i++){
        q.push({srow,scol,0,i,0});
        vis[srow][scol][i][0] = true;
    }
    int ans = INT_MAX;
    while(!q.empty()){
    
        vector<int> temp = q.front();
        q.pop();
        int row = temp[0];
        int col = temp[1];
        int dist = temp[2];
        int dir = temp[3];
        int consec = temp[4];
        if(row==erow && col==ecol){
            cout<<dist<<endl;
            return;
        }
        for(int i = 0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(!valid(nrow,ncol)){
                continue;
            }
           int new_consec;

            if(i == dir){
                new_consec = consec + 1;
            } else {
                new_consec = 1;
            }

            if(new_consec > 3) continue;

            if(!vis[nrow][ncol][i][new_consec]){
                vis[nrow][ncol][i][new_consec] = true;
                q.push({nrow, ncol, dist+1, i, new_consec});
            }
        }
    }
    if(ans!=INT_MAX){
        cout<<ans<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        solve();
    
    return 0;
}