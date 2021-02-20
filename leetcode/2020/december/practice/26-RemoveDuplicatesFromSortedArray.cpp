#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size==0) return 0;
        int lenght=1,prev=nums[0];
        
        for(int i=1; i<size; i++) {
            if(nums[i]!=prev) {
                nums[lenght++]= nums[i];
                prev =nums[i];
            }
        }
        return lenght;
    }
};

int main() {
    vector<int> nums{};
    Solution solution;
    int len  = solution.removeDuplicates(nums);
    for(int i=0; i<len; i++)  cout<< nums[i] <<" ";
    return 0;
}