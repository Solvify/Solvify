#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //basic solution
    int numIdenticalPairs(vector<int>& nums) {
        int size = nums.size(), count = 0;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (nums[i] == nums[j])
                    count++;

        return count;
    }

    // O(n) solution
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> frq;
        for (int num : nums)
            frq[num]++;

        for (auto const& x : frq) {
            int n = x.second;
            count += (n * (n - 1)) / 2;
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums{ 1, 1, 1, 1 };
    cout << solution.numIdenticalPairs(nums);
}