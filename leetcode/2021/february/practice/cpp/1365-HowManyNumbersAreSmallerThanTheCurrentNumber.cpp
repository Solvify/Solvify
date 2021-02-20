#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // basic O(n2) solution 
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(), count;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < n; j++)
                if (i != j && nums[j] < nums[i])
                    count++;
            res.push_back(count);
        }
        return res;
    }

    // O(n) Solution
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int count[101] = { 0 };

        for (int i = 0; i < n; i++)   count[nums[i]]++;

        for (int i = 1; i < 101; i++)   count[i] += count[i - 1];

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                result[i] = 0;
            else
                result[i] = count[nums[i] - 1];

        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums{ 7,7,7,7 };
    for (int num : solution.smallerNumbersThanCurrent(nums))
        cout << num << " ";
    return 0;
}