#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include<unordered_map>
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
    int m;
    cin>>n>>m;
    int maxi = INT_MIN;
    unordered_map<int,int> mpp;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0;j<m;j++){
            cin>>a[i][j];
            mpp[a[i][j]]++;
            maxi = max(maxi,a[i][j]);
        }
    }
    int r=0;
    int c = 0;
    int rowfreq = 0;
    int colfreq = 0;
// row freq nikal raha hu
    for(int i = 0; i<n; i++){
        int temp = 0;
        for(int j= 0;j<m;j++){
            if(a[i][j]==maxi){
                temp++;
            }
        }
        if(temp>rowfreq){
            rowfreq = temp;
            r = i;
        }
    }

    for(int i = 0; i<m; i++){
        int temp = 0;
        for(int j= 0;j<n;j++){
            if(a[j][i]==maxi){
                temp++;
            }
        }
        if(temp>colfreq){
            colfreq = temp;
            c = i;
        }
    }
    int cnt = mpp[maxi];
    // cout<<"cnt"<<cnt<<endl;
    // row ke cnt kam kro
    for(int i=0;i<m;i++){
        if(a[r][i]==maxi){
            cnt--;
        }
    }
    for(int i = 0; i<n; i++){
        if(a[i][c]==maxi){
            cnt--;
        }
    }
    //
    //  cout<<"test"<<endl;
    // cout<<"r->"<<r<<"c->"<<c<<endl;
    if(a[r][c]==maxi){
        cnt++;
    }
    // cout<<"cnt"<<cnt<<endl;
    if(cnt>0){
        cout<<maxi<<endl;
    }
    else{
        cout<<maxi-1<<endl;
    }

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


