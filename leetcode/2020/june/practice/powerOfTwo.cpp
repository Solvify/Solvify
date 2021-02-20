#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        if(n == 1)  return true;
        while (n > 1) {
            if (n % 2 == 1) {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};

int main() {
    int n = -16;
    Solution solution;
    cout << solution.isPowerOfTwo(n) << endl;
    return 0;
}
