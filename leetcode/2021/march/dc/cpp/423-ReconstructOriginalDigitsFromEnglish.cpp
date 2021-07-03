#include<iostream>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        string nums[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

        for (string num : nums) {
            bool res = true;
            for (char num_char : num) {
                for (char ch : s) {
                    if (ch != num_char)  res = false;
                }
            }
        }

    }
};

int main() {
    Solution solution;

    string str = "fviefuro";
    cout << solution.originalDigits(str).c_str() << endl;
    return 0;
}