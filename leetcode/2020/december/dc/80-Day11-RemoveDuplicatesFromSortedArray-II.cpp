#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    Solution() {
		ios_base::sync_with_stdio(false); cin.tie(NULL);
	}
    // my solution for frequency K
    int removeDuplicates(vector<int>& nums) {
        int i=0,j,count=1,size=nums.size();
        if(size<=2) return size;
        for(j=1; j<size; j++) {
            if(nums[i]!=nums[j]) {
                nums[++i] = nums[j];
                count = 1;
            } else if(nums[i] == nums[j] && count <2) {
                count++;
                nums[++i] = nums[j];
            }
        }
        i-=count-1;
        while (count--){
           nums[i++] = nums[size-1];
        }
        return i;
    } 
    // effieint solution for frequency K
    int removeDuplicates(vector<int>& nums) {
      auto len=0, dup=0;
      for (int i=0; i<nums.size(); i++) {
        if (i>0 && nums[i]==nums[i-1]) {
          if (dup>1) continue;
          else dup++;
        } else {
          dup=0;
        }
        nums[len++]=nums[i];
      }
      return len;
    }

};

int main() {
    vector<int> arr {1,1,1,2,2,3,3,3,3,4,4,5,5,5,5};
    Solution solution;
    int index = solution.removeDuplicates(arr);
    
    for(int i=0; i<index; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}