#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // with extra space
    void moveZeroes(vector<int>& nums) {
        vector<int> res;
        int number_of_zeros=0;
        for(int num : nums) 
            if(num) res.push_back(num);
            else    number_of_zeros++;
        
        while (number_of_zeros--){
            res.push_back(0);
        }
        nums = move(res);
        
    }
    // with constant space
    void moveZeroes(vector<int>& nums) {
        int writeptr=0,size = nums.size();
        for(int i=0; i<size; i++) 
            if(nums[i]!=0)
                nums[writeptr++] = nums[i];
        
        while (writeptr < size)
            nums[writeptr++] = 0;
    }
};


int main() {
    vector<int> nums{0,1,0,3,0,0,12,3,0,13,0,0};
    Solution solution;
    solution.moveZeroes(nums);
    for(int num : nums) cout << num << " ";
    return 0;
}