#include <iostream>
#include <vector>
using namespace std;

bool isPalindromeNotX(vector<int> a,int x){
    int n = a.size();
    int l = 0;
    int r = n-1;
    bool ans = true;
    while(r>l){
        while(r>l && a[r]==x){
            r--;
        }
        while(r>l && a[l]==x){
            l++;
        }
        if(a[r] != a[l]){
            ans = false;
            break;
        }
        r--;
        l++;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<"YES"<<endl;
        return;
    }
    int elea = -1;
    int eleb = -1;
    int l = 0;
    int r = n-1;
    while(r>l){
        if(a[l]!=a[r]){
            elea = a[l];
            eleb = a[r];
            break;
        }
        r--;
        l++;
    }
    if (elea == -1) {
        cout << "YES" << endl;
        return;
    }
    if(isPalindromeNotX(a,elea) || isPalindromeNotX(a,eleb)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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