#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i(1); i < nums.size(); i++)
            nums[i] = nums[i - 1] + nums[i];
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums{ 1,1,1,1,1 };
    for (int num : solution.runningSum(nums))
        cout << num << " ";
    return 0;
}