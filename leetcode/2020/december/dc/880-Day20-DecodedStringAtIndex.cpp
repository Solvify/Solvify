#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string curr = "";
        for (char ch : S) {
            if (isdigit(ch)) {
                cout << "In If ======>" << endl;
                int len = 0, num = ch - '0';
                while (--num) {
                    len = curr.length();
                    cout << "num ======> " << num << " K==> " << K << " curr len : " << len << endl;
                    if (K <= 0)
                        break;
                    else {
                        curr += curr;
                        K -= len;
                    }

                }
            } else {
                curr += ch;
                cout << "In elses ======> " << endl;
                if (!(--K)) break;
            }
        }
        printf("curr: %s, K: %d\n", curr.c_str(), K);
        if (K >= 0) {
            return curr.substr(curr.length() - 1 - K, 1);
        } else {
            return curr.substr(-K - 1, 1);
        }

    }
};

int main() {
    Solution solution;
    string str = "a2345678999999999999999";
    str = solution.decodeAtIndex(str, 10000);
    printf("%s\n", str.c_str());

    return 0;
}