#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int max = INT32_MIN, pos=0,appeared=0;
        for(int num : nums) {
            if(max < num) {
                nums[pos++] = num; 
                max = num;
                appeared = 1;
            } 
            else if(appeared++ < 2) {
                nums[pos++] = num; 
            }
        }
        nums.erase(nums.begin()+pos,nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> nums= {0,1,2,2,2,3,3,3,22};
    Solution solution;
    cout << solution.removeDuplicates(nums) << endl;
    for(int num :nums) cout << num << " ";
}