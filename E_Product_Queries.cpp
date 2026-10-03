#include <bits/stdc++.h>
using namespace std;

/* ---------- GLOBAL ---------- */
const int MAXN = 1000000;
int spf[MAXN + 1];   // smallest prime factor


/* ---------- Build SPF ---------- */
void build_spf(int n) {
    for (int i = 1; i <= n; i++)
        spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {          // i is prime
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


/* ---------- Prime factor count ---------- */
map<int,int> factor_count(int x) {
    map<int,int> cnt;

    while (x > 1) {
        int p = spf[x];
        cnt[p]++;
        x /= p;
    }

    return cnt;
}


/* ---------- Solve ---------- */
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)cin>>a[i]; 

    build_spf(n);
    map<int,int> factors;
    for (int i = 1; i <= n; i++) {
        factors = factor_count(i);

        // for (auto &it : factors) {
        //     cout << it.first << " comes " << it.second << " times ";
        // }
        // cout << "\n";
    }
    vector<int> ans;
    set<int> st;
    for(int i =  0;i<n;i++){
        st.insert(a[i]);
    }
    for(int i = 1;i<=n;i++){
        for(auto it:factors+){

        }
    }
}


/* ---------- Main ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
