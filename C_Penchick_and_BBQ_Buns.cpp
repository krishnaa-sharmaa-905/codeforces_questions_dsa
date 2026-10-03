#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
       int n;
       cin>>n;
       if(n%2==0){
           for(int i =  1;i<=n/2;i++){
               cout<<i<<" "<<i<<" ";
           }
           cout<<endl;
       }

       else{
           if(n<27){
               cout<<-1<<endl;
               return;
           }
           else{
                cout<<"1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
                for(int i = 14;i<=n/2;i++){
                    cout<<i<<" "<<i<<" ";
                }
                cout<<endl;
           }
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