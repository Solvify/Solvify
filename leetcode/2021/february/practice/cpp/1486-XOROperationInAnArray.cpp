#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start + 2 * 0;
        for (int i(1); i < n; i++)
            res ^= start + 2 * i;
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.xorOperation(10, 5) << endl;
    return 0;
}