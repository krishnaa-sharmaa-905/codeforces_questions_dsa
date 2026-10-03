#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ans;

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> empty;
        int sum = 0;
        help(nums, sum, 0, empty);
        return ans;
    }

    void help(vector<int>& nums, int& sum, int ind, vector<int> temp) {
        if (ind >= nums.size()) {
            ans.push_back(sum);
            return;
        }

        // take
        temp.push_back(nums[ind]);
        sum+= nums[ind];
        help(nums, sum, ind + 1, temp);

        // not take
        temp.pop_back();
         sum-=nums[ind];
        help(nums, sum, ind + 1, temp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // sample input
    vector<int> result = sol.subsetSums(nums);

    cout << "Subset sums: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
