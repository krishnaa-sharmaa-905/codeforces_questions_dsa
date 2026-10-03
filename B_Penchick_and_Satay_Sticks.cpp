#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    bool ans = true;
    for (int i = 0; i < n-1; i++) {
        if(arr[i]==i+1) {
            continue;
        }
        else{
            if(arr[i]==i+2 && arr[i+1]==i+1){
                
                    swap(arr[i],arr[i+1]);
                
                
            }
            else{
                    ans = false;
                    break;
                }
        }
        
    }
    if(ans){
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