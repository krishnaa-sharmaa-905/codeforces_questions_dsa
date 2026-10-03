#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

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

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1 ; i++){
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert to 0-based index
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i = 0;i<n;i++){
    //     cout<<adj[i].size()<<" ";
    // }
    int leaf = 0;
    unordered_map<int, int> lmpp;
    for(int i = 0; i < n; i++) {
        // sort(adj[i].begin(), adj[i].end());
        if (adj[i].size() == 1) {
            leaf++;
            lmpp[adj[i][0]]--;
            lmpp[i]--; 
        }

    }
    int ans = leaf;
    for(int i = 0;i<n;i++){
        if(lmpp.find(i) != lmpp.end()) {
            ans  = min(ans, leaf+lmpp[i]);
        }
    }
    cout<<ans<<endl;
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