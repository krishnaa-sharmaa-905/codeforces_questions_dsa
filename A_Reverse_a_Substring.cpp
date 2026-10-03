#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l = 0;
    int r = 0;
    for(int i = 0; i<n-1; i++){
        if(s[i]>s[i+1]){
            l=i+1;
            r = i+1+1;
            break;
        }
    }
    if(l+r!=0){
        cout<<"YES"<<endl;
        cout<<l<<" "<<r;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
    return 0;
}