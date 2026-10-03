#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<vector<char>> a(n,vector<char>(n));

    for(int i =  0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int ans = 0;
    
    for(int i=  0;i<n ;i++){
        for(int j = 0;j<n ;j++){
            int cnt0 = 0;
            int cnt1 = 0;

            if(a[i][j]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }

            if(a[n-1-j][i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }

            if(a[j][n-1-i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }

            if(a[n-1-i][n-1-j]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }

            if ((cnt0 == 0) || (cnt1 == 0))
					continue;

            else{            
                if(cnt0>=cnt1){
                    a[n-1-i][n-1-j] = '0';
                    a[j][n-1-i] = '0';
                    a[i][j] = '0';
                    a[n-1-j][i] = '0';
                }
                else{
                    a[n-1-i][n-1-j] = '1';
                    a[j][n-1-i] = '1';
                    a[i][j] = '1';
                    a[n-1-j][i] = '1';
                }
            }
            ans += min(cnt0,cnt1);
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