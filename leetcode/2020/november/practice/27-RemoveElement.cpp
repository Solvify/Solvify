#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int till = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[till++] = nums[i];
            }
        }
        cout << till <<" ==>"<<endl;
        nums.erase(nums.begin()+till,nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> nums = {3,5};
    int value = 5;
    Solution solution;

    cout << solution.removeElement(nums,value) << endl;

    for(int num : nums) cout << num << " ";

    return 0;
}