#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums) ans.push_back(num * num);
        sort(ans.begin(),ans.end());
        return ans;
    }
    // best solution
    vector<int> sortedSquares(vector<int>& A) {
        int l = 0, r = A.size()-1;
        vector<int> result;
        while(l <= r){
            if(abs(A[l]) < abs(A[r])){
                result.push_back(A[r] * A[r]);
                r--;
            }else{
                result.push_back(A[l] * A[l]);
                l++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> sortedSquares(vector<int>& A) {
        transform(A.begin(), A.end(), A.begin(), [](const auto value){
            return value*value;
        });
        sort(A.begin(), A.end());
        return A;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-7,-3,2,3,11};
    nums = solution.sortedSquares(nums);
    for(int num : nums) cout << num << " ";
    return 0;
}