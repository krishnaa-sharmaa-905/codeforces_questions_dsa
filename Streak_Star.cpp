#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        nums[i] =num; 
    }
    //solve karna start
    int ans = 0;
    
     for (int i = 0; i < n; i++) {
        int original = nums[i];
        nums[i] *= x; 

        int temp_ans = 1, temp_curr = 1;
        for (int j = 1; j < n; j++) {
            if (nums[j] >= nums[j - 1]) {
                temp_curr++;
            } else {
                temp_curr = 1;
            }
            temp_ans = max(temp_ans, temp_curr);
        }

        ans = max(ans, temp_ans); 
        nums[i] = original; 
    }
    cout<<ans<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}