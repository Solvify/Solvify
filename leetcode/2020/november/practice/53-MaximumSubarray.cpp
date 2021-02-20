#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int largest_sum = INT32_MIN;
        for(int num : nums) largest_sum+=num;
        while (start < end) {
            
            
        }
        
        
    }
};

int main() {
    vector<int> nums {1,2,3,4,5,6};
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}