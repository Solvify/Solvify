#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0, sum;
        for (auto account : accounts) {
            sum = 0;
            for (int wealth : account)
                sum += wealth;
            if (max < sum)
                max = sum;
        }
        return max;
    }
};

int main() {
    vector<vector<int>> accounts{ {2, 8, 7}, {7, 1, 3}, {1, 9, 5} };
    Solution solution;
    cout << solution.maximumWealth(accounts) << endl;
}