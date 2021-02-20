#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int n = num.size();
        for(char c: num) {
            while( !s.empty() && s.top()>c && k >0) {
                cout<<"top of the stack : "<<s.top()<<" current number : "<<c<<" k : "<<k<<endl;
                s.pop();
                --k;
            }
            if(!s.empty() || c!='0')
                s.push(c);
        }

        while (!s.empty() && k>0) {
            s.pop();
            --k;
        }
        if(s.empty())
            return "0";

        while (!s.empty()) {
            num[n-1] = s.top();
            s.pop();
            --n;
        }

        return num.substr(n);
    }
};
int main() {

    string s = "112";
    int k = 1;
    Solution solution;
    cout<<solution.removeKdigits(s,k);

}