#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        for (char ch : t) mp[ch]--;

        for (auto entry : mp) {
            if (entry.second != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "rat", t = "car";
    cout << solution.isAnagram(s, t) << endl;
    return 0;
}