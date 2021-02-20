#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string first_str = strs[0];
        int ans = first_str.length();
        for(int i = 1; i < strs.size(); i++) {
            int curr_matched=0;
            for(int j=0; j< first_str.length(); j++) {
                if(first_str[j] != strs[i][j]) break;
                curr_matched++;
            }
            if(curr_matched < ans)  ans = curr_matched;
        }
        return first_str.substr(0, ans); 
    }
};

int main() {
    vector<string> strs{};
    Solution solution;
    printf("%s\n",solution.longestCommonPrefix(strs).c_str());
    return 0;
}