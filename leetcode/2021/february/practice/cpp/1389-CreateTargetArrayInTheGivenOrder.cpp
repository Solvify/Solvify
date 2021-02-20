#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans;
        for (int i(0); i < n; i++) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums{ 0,1,2,3,4 };
    vector<int> index{ 0,1,2,2,1 };
    for (int num : solution.createTargetArray(nums, index)) {
        cout << num << " ";
    }
    return 0;
}