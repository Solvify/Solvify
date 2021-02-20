#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_word_length = 0,count=0;
        for(char ch : s) {
            if(ch == ' ') {
                if(count > 0 )   last_word_length = count;
                count =0;
            } else {
                count++;
            }
        }
        if(count > 0 )   last_word_length = count;
        return last_word_length;
    }
};

int main() {
    string str = " hello ";
    Solution solution;
    cout << solution.lengthOfLastWord(str) << endl;
    return 0;
}