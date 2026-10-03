#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }
    for(int i = 0; i<n; i++){
        cin>>y[i];
    }
    vector<int> diffneg;
    vector<int> diffpos;
    vector<int> diff;
    for(int i = 0;i<n;i++){
        int sub = y[i]-x[i];
        diff.push_back(sub);
    }
    sort(diff.begin(),diff.end(),greater<int>());
    
    int j = n-1;
  
    int ans = 0;

    for(int i = 0; i<n; i++){
        while(i<j && diff[i]+diff[j]<0){
            j--;
        }
        if(j<=i){
            break;
        }
        j--;
        ans++;
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