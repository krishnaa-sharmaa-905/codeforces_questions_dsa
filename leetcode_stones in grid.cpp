#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        string start = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += to_string(grid[i][j]);
            }
        }
        
        string target = "111111111";
        if (start == target) return 0;
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        
        q.push({start, 0});
        visited.insert(start);
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            
            if (curr == target) return moves;
            
            for (int i = 0; i < 9; ++i) {
                if (curr[i] > '0') {
                    int r = i / 3;
                    int c = i % 3;
                    
                    for (auto& d : dirs) {
                        int nr = r + d[0];
                        int nc = c + d[1];
                        
                        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
                            int ni = nr * 3 + nc;
                            string next_state = curr;
                            next_state[i]--;
                            next_state[ni]++;
                            
                            if (visited.find(next_state) == visited.end()) {
                                visited.insert(next_state);
                                q.push({next_state, moves + 1});
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
    
};
int main(){
    vector<vector<int>> grid = {{9,0,0},{0,0,0},{0,0,0}};
    Solution obj;
    cout<<obj.minimumMoves(grid)<<endl;
}