#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isConsistentString(string a, string g) {
        unordered_map<char, int> allow;
        for (char ch : a)
            allow[ch]++;
        bool res = true;
        for (char ch : g)
            res = res && allow[ch];
        return res;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for (string s : words)
            if (isConsistentString(allowed, s))
                count++;
        return count;
    }

    // another solution
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool alpha[26] = {};
        for (char c : allowed)
            alpha[c - 'a'] = true;
        for (string word : words) {
            for (char c : word) {
                if (!alpha[c - 'a']) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string str = "cad";
    vector<string> words{ "cc", "acd", "b", "ba", "bac", "bad", "ac", "d" };
    cout << solution.countConsistentStrings(str, words) << endl;
    return 0;
}