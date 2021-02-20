#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int size = s.length();
        for (int i=0; i< size; i++) {
            switch (s[i])
            {
            case 'M':
                if(i > 0 && s[i-1] == 'C') res+=900;
                else    res+=1000;
                break;
            case 'D':
                if(i > 0 && s[i-1] == 'C') res+=400;
                else    res+=500;
                break;
            case 'L':
                if(i > 0 && s[i-1] == 'X') res+=40;
                else    res+=50;
                break;
            case 'V':
                if(i > 0 && s[i-1] == 'I') res+=4;
                else    res+=5;
                break;
            case 'C':
                if(i > 0 && s[i-1] == 'X') res+=90;
                else if (i < size-1 && (s[i+1] == 'D' || s[i+1] == 'M' )) continue;
                else    res+=100;
                break;
            case 'X':
                if(i > 0 && s[i-1] == 'I') res+=9;
                else if (i < size-1 && (s[i+1] == 'L' || s[i+1] == 'C' )) continue;
                else    res+=10;
                break;
            default:
                if (i < size-1 && (s[i+1] == 'V' || s[i+1] == 'X' )) continue;
                else    res+=1;
                break;
            }
        }
        return res;
    }
};

int main() {
    string str = "DCCCXLV";
    Solution solution;
    cout << solution.romanToInt(str) << endl;
    return 0;
}