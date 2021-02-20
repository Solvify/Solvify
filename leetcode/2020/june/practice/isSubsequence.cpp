#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
//        unordered_map<char,int> mp_s,mp_t;
//        for(char c : t) ++mp_t[c];
//        for(char c : s) ++mp_s[c];
//
//        for(auto & i : mp_s) cout<<i.first<<" "<<i.second<<endl;
        //for(auto & i : mp_t) cout<<i.first<<" "<<i.second<<endl;
        int i=0,j=0,t_size = t.size(),s_size = s.size(),count=0;
        while (j<t_size) {
            if(s[i]==t[j]) {
                i++;
                count++;
            }
            j++;
        }

        return (s_size==count);

    }
};
int main() {
    string s = "axc", t = "ahbgdc";
    Solution solution;
    std::cout << solution.isSubsequence(s,t)<< std::endl;
    return 0;
}