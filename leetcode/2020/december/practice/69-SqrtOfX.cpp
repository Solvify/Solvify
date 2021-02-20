#include<iostream>
using namespace std;

class Solution {
public:
    // leaner solution
    int mySqrt(int x) {
        return sqrt(x);
        long long i = 1;
        while ((i * i) <= x)   i++;
        return i - 1;
    }

    // Binary Solution with iterative approch
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int left = 1, right = x;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(2147483647) << endl;
    return 0;
}