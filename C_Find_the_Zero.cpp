#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = -1;

        for (int i = 1; i < n; i++) {
            cout << "? " << 2 * i + 1 << " " << 2 * i + 2 << endl;
            cout.flush();

            int res;
            cin >> res;

            if (res == -1) exit(0);

            if (res) {
                ans = 2 * i + 1;
                break;
            }
        }

        if (ans == -1) {
            cout << "? " << 1 << " " << 3 << endl;
            cout.flush();

            int res;
            cin >> res;

            if (res == -1) exit(0);

            if (res) {
                ans = 1;
            } else {
                cout << "? " << 1 << " " << 4 << endl;
                cout.flush();

                cin >> res;

                if (res == -1) exit(0);

                if (res) {
                    ans = 1;
                } else {
                    ans = 2;
                }
            }
        }

        cout << "! " << ans << endl;
        cout.flush();
    }

    return 0;
}