#include <iostream>

using namespace std;

class Solution
{
public:
    string toLowerCase(string str)     {
        for (int i = 0; i < str.length(); i++)
            if (str[i] >= 65 && str[i] <= 91)
                str[i] = str[i] + 32;
        return str;
    }
};

int main() {
    Solution solution;
    string str = "Hello";
    printf("%s", solution.toLowerCase(str).c_str());
    return 0;
}