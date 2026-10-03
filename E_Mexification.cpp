#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> help(vector<int>& nums) {
    int n=  nums.size();
    
    sort(nums.begin(), nums.end());
    vector<int> ans(n,0);
    int mex = 0;
    for (int idx = 0; idx < n; idx++){
        if (nums[idx] == mex){
            mex += 1;
        }
    }
    // cout<<"Debug mex: "<<mex<<endl;
    // cout<<mex<<endl;
    // vector<int> res;
    unordered_map<int,int> mpp;
    for(auto it:nums){
        mpp[it]++;
    }

    for(int i = 0; i<nums.size(); i++){
        if(nums[i]>mex){
            ans[i] = mex;
        }
        else if(nums[i]<=mex && mpp[nums[i]]==1){
            ans[i] = nums[i];
        }
        else if(mpp[nums[i]]>1 && nums[i]<mex){
            ans[i] = mex;
        }
    }
    return ans;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin>>nums[i];

    vector<int> ans1 = help(nums);

    vector<int> ans2 = help(ans1);
    vector<int> ans3 = help(ans2);
    // cout<<"Debug: ";
    // for(auto it: ans1){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it: ans2){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    if(k==1){
        cout<<accumulate(ans1.begin(),ans1.end(),0)<<endl;
        return;
    }
    
    else{
        if(k%2==0){
            cout<<accumulate(ans2.begin(),ans2.end(),0)<<endl;
            return;
        }
        else{
            cout<<accumulate(ans3.begin(),ans3.end(),0)<<endl;
            return; 
        }
    }
    // int ans = 0;
    
    // cout<<ans<<endl;

  
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