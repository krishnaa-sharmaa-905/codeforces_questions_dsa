#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int max_a = n + m + 1;

    vector<int> cnt_b(max_a, 0), cnt_a(max_a, 0);

    for (int i = 0; i < n; i++){
        cnt_a[a[i]]++;
    }

    for (int i = 0; i < m; i++){
        cnt_b[b[i]]++;
    }

    vector<int> cnt_del(max_a, 0);

    int f = 0, s = 0, com = 0;

    for (int i = 1; i < max_a; i++){
        for (int j = i; j < max_a; j += i){
            cnt_del[j] += cnt_a[i];
        }
    }

    for (int i = 1; i < max_a; i++){
        if (cnt_b[i] == 0){
            continue;
        }

        if (cnt_del[i] == 0){
            s += cnt_b[i];
        }
        else if (cnt_del[i] == n){
            f += cnt_b[i];
        }
    }

    com = m - f - s;

    bool turn = 0;
    string win = "";

    while(1){
        if (turn == 0){
            if (com > 0){
                com--;
            }
            else if (f > 0){
                f--;
            }
            else{
                win = "Bob";
                break;
            }
        }
        else{
            if (com > 0){
                com--;
            }
            else if (s > 0){
                s--;
            }
            else{
                win = "Alice";
                break;
            }
        }
        turn = !turn;
    }

    cout << win << '\n';
	
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