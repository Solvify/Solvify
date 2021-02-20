#include<iostream>
#include<regex>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        return haystack.find(needle);
    }
};

int main () {
    string haystack = "mississippi", needle = "issip";
    Solution solution;
    cout << solution.strStr(haystack,needle) << endl;
    return 0;
}
