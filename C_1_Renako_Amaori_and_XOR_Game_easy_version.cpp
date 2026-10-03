#include <iostream>
#include <vector>
using namespace std;

void print(int ans){
    if(ans==0){
        cout<<"Tie"<<endl;
    }
    else if(ans==1){
        cout<<"Ajisai"<<endl;
    }
    else if(ans==2){
        cout<<"Mai"<<endl;
    }
}

void solve() {
    int n;
    cin>>n;vector<int> a(n);
    vector<int> b(n);
    int cnt1 = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) cnt1++;
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
        if(b[i]==1) cnt1++;
    }
    
    if(cnt1%2==0){
        print(0);
        return;
    }

    for(int i = n-1;i>=0;i--){
        if(a[i]!=b[i]){
            if(i%2==0){
                print(1);
                return;
            }
            else{
                print(2);
                return;
            }
        }
        else{
            continue;
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