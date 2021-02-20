#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffled;
        for (int i = 0; i < n; i++) {
            shuffled.push_back(nums[i]);
            shuffled.push_back(nums[i + n]);
        }
        return shuffled;
    }
};

int main() {
    Solution solution;
    vector<int> nums{ 1, 1, 2, 2 };
    for (int num : solution.shuffle(nums, nums.size() / 2)) {
        cout << num;
    }
}