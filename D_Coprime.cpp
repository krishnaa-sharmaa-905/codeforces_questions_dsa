#include <iostream>
#include <vector>
using namespace std;

const int MAX_A = 1000;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;

    vector<int> lastIndex(MAX_A + 1, -1);
    
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        lastIndex[x]=i+1; 
    }

    int ans=-1;

    for (int x=1;x<=MAX_A;x++) {
        for (int y=x;y<=MAX_A;y++) {
            if (lastIndex[x]!=-1 && lastIndex[y]!=-1 && gcd(x, y) == 1) {
                ans = max(ans, lastIndex[x] + lastIndex[y]);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
