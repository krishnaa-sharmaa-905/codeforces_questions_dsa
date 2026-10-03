#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    //j is previous
    int cnt  = 1;
    int j=0;
    for(int i =1;i<n;i++ ){
        if(a[i]>a[j]+1){
            cnt++;
        }
        else{
            while(i<n && a[i]<=a[j]+1){
                i++;
            }
            if(i<n && a[i]>a[j]+1){
                cnt++;
                

            }
        }
        j=i;
    }
   
    cout<<cnt<<endl;
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