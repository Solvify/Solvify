#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int precedence(char op){
        if(op == '+' || op == '-')
        return 1;
        if(op == '*' || op == '/')
        return 2;
        return 0;
    }

    int applyOp(int a, int b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default : return 0;
        }
    }
    int calculate(string s) {
        int i;
        stack <int> values;
        stack <char> ops;

        for(i = 0; i < s.length(); i++) {

            if(s[i] == ' ')
                continue;

            else if(isdigit(s[i])) {
                int val = 0;

                while(i < s.length() && isdigit(s[i])) {
                    val = (val*10) + (s[i]-'0');
                    i++;
                }
                values.push(val);
                i--;
            } else {

                while(!ops.empty() && precedence(ops.top()) >= precedence(s[i])){
                    int val2 = values.top();
                    values.pop();

                    int val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(applyOp(val1, val2, op));
                }
                ops.push(s[i]);
            }
        }

        while(!ops.empty()){
            int val2 = values.top();
            values.pop();

            int val1 = values.top();
            values.pop();

            char op = ops.top();
            ops.pop();

            values.push(applyOp(val1, val2, op));
        }

        return values.top();
    }
    // Best Solution ever
    int evaluate(string s) {
        int result=0, num=0, curnum=0;
        int op='+';
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num*10 + (c-'0');
            }
            if (c=='+'||c=='-'||c=='*'||c=='/'||i==s.size()-1) {
                switch(op) {
                    case '+': curnum = num; break;
                    case '-': curnum = -num; break;
                    case '*': curnum *= num; break;
                    case '/': curnum /= num; break;
                }
                
                if (c=='+'||c=='-'||i==s.size()-1) {
                    result += curnum;
                }
                
                num=0;
                op = c;
            }
        }
        
        return result;
    }
};



int main() {
    Solution solution;
	cout << solution.calculate("10 + 2 * 6") << "\n";
	cout << solution.evaluate("100 * 2 + 12") << "\n";
	return 0;
}
