#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fact(int n){
        return (n == 0)? 1 : n*fact(n-1);
    }
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int tortoise = nums[0];
        int hare = nums[0];

        while (true) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (tortoise == hare)
                break;
        }
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return tortoise;
    }
};
int main() {
    vector<int> arr{1,2,1,4,1};
    Solution solution;
    cout<<solution.findDuplicate(arr)<<endl;
    return 0;
}