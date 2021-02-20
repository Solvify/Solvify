#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return 0;
        stack<char> st;
        for(char ch : s) {
            switch (ch) {
            case ')':   
                if(st.size() != 0 && st.top() == '(') st.pop();
                else    st.push(ch);
                break;
            case '}':   
                if(st.size() != 0 && st.top() == '{') st.pop();
                else    st.push(ch);
                break;
            case ']':   
                if(st.size() != 0 && st.top() == '[') st.pop();
                else    st.push(ch);
                break;
            default:
                st.push(ch);
                break;
            }
        }
        return !st.size();
    }
};

int main() {
    string str = "";
    Solution solution;
    cout << solution.isValid(str) << endl;
    return 0;
}