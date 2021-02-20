#include <iostream>

using namespace std;

class Solution
{
public:
    int maxDepth(string s) {
        int depth = 0, temp = 0;
        for (char ch : s) {
            if (ch == '(')
                temp++;
            if (ch == ')') {
                if (depth < temp)
                    depth = temp;
                temp--;
            }
        }
        return depth;
    }
};

int main() {
    Solution solution;
    string str = "1";
    cout << solution.maxDepth(str) << endl;
    return 0;
}