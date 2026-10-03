#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i<m; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> diff(m);
    for (int i = 0; i < m; i++) {
       
        int next = (i + 1) % m;
        diff[i] = (a[next] - a[i] - 1 + n) % n;
    }
    sort(diff.begin(),diff.end());
    int protectedCount = 0;
    int day = 0;
    for(int i = m-1;i>=0;i--){
        diff[i] -= 2*day;
        if (diff[i] <= 0) continue;
        if(diff[i]==1){
           day++;
           protectedCount++;
        }
            // protectedCount = protectedCount + diff[i] - 1;

        else if(diff[i]>1){
            protectedCount = protectedCount + diff[i] - 1;
            
            day+=2;
        }
        
    }
    cout << n-protectedCount << endl;

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