#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution solution;
    // cout << solution.numberOfSteps(123) << endl;
    int test = stoi("123");
    test++;
    cout << test << endl;
    return 0;
}