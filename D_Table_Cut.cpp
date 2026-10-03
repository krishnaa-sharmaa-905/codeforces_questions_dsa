#include <iostream>
#include <vector>
using namespace std;

void problem();

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) problem();
    return 0;
}

void problem() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    long long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {cin >> arr[i][j]; total += arr[i][j];}
    }

    long long target = total/2;
    long long current = 0;
    vector<int> table(n, 0);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (current >= target) break;
            current += arr[i][j];
            table[i]++;
        }
    }

    cout << target * (total - target) << endl;
    int prev = 0;
    int rs = 0;

    for (int i = 0; i < n; i++) {
        for (int k = prev; k < table[i]; k++) {
            cout << "R";
            rs++;
        }
        cout << "D";
        prev = table[i];
    }

    for (int k = rs; k < m; k++) cout << "R";

    cout << endl;
}