#include <iostream>

using namespace std;

class Solution
{
public:
    string interpret(string command) {
        char prev;
        string res = "";
        for (char ch : command) {
            if (ch == ')') {
                if (prev == '(')
                    res += 'o';
                else
                    res += "al";
            }
            if (ch == 'G')
                res += ch;
            prev = ch;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string str = "(al)G(al)()()G";
    printf("%s", solution.interpret(str).c_str());
    return 0;
}