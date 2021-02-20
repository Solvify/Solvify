#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // Simple solution
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)  factors.push_back(i);
        }
        return (factors.size() < k) ? -1 : factors[k - 1];
    }
    // Smart Solution
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                k--;
                if (k <= 0)    return i;
            }
        }
        return -1;
    }

};

int main() {
    Solution solution;

    cout << solution.kthFactor(1000, 3) << endl;

    return 0;
}