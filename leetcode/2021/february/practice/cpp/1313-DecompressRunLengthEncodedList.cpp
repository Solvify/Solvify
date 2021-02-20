#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i(0); i < nums.size(); i += 2)
            for (int j(0); j < nums[i]; j++)
                res.push_back(nums[i + 1]);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{ 1,1,2,3 };
    for (int num : solution.decompressRLElist(nums))
        cout << num << " ";
    return 0;
}