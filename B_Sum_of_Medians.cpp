#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
		cin >> n >> k; 
		vector<long long> v(n * k); 
		for (int i = 0; i < n * k; i++)
			cin >> v[i];

		long long pointer = n * k; 

		long long sum = 0; 
		while (k--) 
		{
			pointer -= (n / 2 + 1);
			sum += v[pointer]; 
		}
		cout << sum << endl;
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