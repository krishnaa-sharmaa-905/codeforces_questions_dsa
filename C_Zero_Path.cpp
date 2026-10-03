#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    if((n + m - 1) % 2 != 0){
        cout << "NO\n";
        return;
    }

    vector<vector<int>> mn(n, vector<int>(m));
    vector<vector<int>> mx(n, vector<int>(m));

    mn[0][0] = mx[0][0] = a[0][0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(i == 0 && j == 0) continue;

            int min_val = INT_MAX;
            int max_val = INT_MIN;

            if(i > 0){
                min_val = min(min_val, mn[i-1][j]);
                max_val = max(max_val, mx[i-1][j]);
            }

            if(j > 0){
                min_val = min(min_val, mn[i][j-1]);
                max_val = max(max_val, mx[i][j-1]);
            }

            mn[i][j] = min_val + a[i][j];
            mx[i][j] = max_val + a[i][j];
        }
    }

    if(mn[n-1][m-1] <= 0 && mx[n-1][m-1] >= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}