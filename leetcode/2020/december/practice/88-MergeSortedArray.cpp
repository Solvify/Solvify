#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    vector<int> nums1{ 1,2,3,0,0,0 };
    vector<int> nums2{ 2,5,6 };

    Solution solution;

    solution.merge(nums1, 3, nums2, 3);

    for (int num : nums1)    cout << num << " ";

    return 0;
}