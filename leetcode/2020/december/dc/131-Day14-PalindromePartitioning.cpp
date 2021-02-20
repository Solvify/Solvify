#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool is_palindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> test;
        return test;
    }
};

int main() {
    string str = "abbc";
    Solution solution;
    for (vector<string> row : solution.partition(str)) {
        for (string s : row) {
            printf("%s ", s);
        }
        cout << endl;
    }
    cout << solution.is_palindrome(str) << endl;
    return 0;
}