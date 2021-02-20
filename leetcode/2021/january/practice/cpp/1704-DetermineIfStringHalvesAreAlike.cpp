#include <iostream>

using namespace std;

class Solution
{
public:
    bool isVovel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    bool halvesAreAlike(string s) {
        int len = (s.length() / 2) - 1;
        int count = 0;
        for (char ch : s) {
            if (isVovel(ch)) {
                if (len >= 0)
                    count++;
                else
                    count--;
            }
            len--;
        }
        return !count;
    }
};

int main() {
    Solution solution;
    string str = "AbCdEfGh";
    cout << solution.halvesAreAlike(str) << endl;
    return 0;
}