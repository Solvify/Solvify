#include <iostream>

using namespace std;

class Solution
{
public:
    string defangIPaddr(string address) {
        string res = "", temp = "";
        for (char ch : address) {
            if (ch == '.') {
                res += temp + "[.]";
                temp = "";
            } else
                temp += ch;
        }
        if (temp != "")
            res += temp;
        return res;
    }
};

int main() {
    string str = "1.1.1.1";
    Solution solution;
    printf("%s\n", solution.defangIPaddr(str).c_str());

    return 0;
}