#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin>>nums[i];
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(i==0 || i== n-1){
            ans.push_back(nums[i]);
            continue;
        }
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            ans.push_back(nums[i]);
        }
        if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
            ans.push_back(nums[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(int i = 0; i<(int)ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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