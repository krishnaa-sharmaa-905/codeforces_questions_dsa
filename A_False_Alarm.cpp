#include <iostream>
#include <vector>
using namespace std;


void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    int last1 = -1;
    int first1 =-1;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]==1 && first1==-1){
            first1 = i;
        }
        else if(a[i]==1 && first1!=-1){
            last1 = i;
        }
    }
    int diff = last1-first1+1;
    
    if(diff>x){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
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