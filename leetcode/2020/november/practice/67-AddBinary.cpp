#include<iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        char carry = '0';
        int a_size = a.length(), b_size = b.length();
        int min_len = a_size < b_size ? a_size : b_size;
        int i;
        for(i = min_len-1; i >= 0; i--) {
            if(a[i] == b[i]) {
                if(carry != '0') {
                    if(a[i]=='1')   carry = '1';
                    else carry = '0';
                    res = '1'+res;
                } else {
                    if(a[i]=='1')   carry = '1';
                    else carry = '0';
                    res = '0'+res;
                }
            } else {
                if(carry != '0') {
                    carry = '1';
                    res = '0'+res;
                } else {
                    carry = '0';
                    res = '1'+res;
                }
            }
        }

        while(i < a_size-1) {
            if(carry == '1') {
                if(a[i] == '1')  {
                    res = '0'+res;
                    carry = '1';
                } else {
                    res = '1'+res;
                    carry = '0';
                }    
            } else {
               if(a[i] == '1')  {
                    res = '1'+res;
                } else {
                    res = '0'+res;
                } 
                carry = '0'; 
            }
            i++;
        }
        while(i < b_size-1) {
            if(carry == '1') {
                if(b[i] == '1')  {
                    res = '0'+res;
                    carry = '1';
                } else {
                    res = '1'+res;
                    carry = '0';
                }    
            } else {
               if(b[i] == '1')  {
                    res = '1'+res;
                } else {
                    res = '0'+res;
                } 
                carry = '0'; 
            }
            i++;
        }

        if(carry != '0')   res = '1'+res;

        printf("%s\n",res.c_str());

        return res;
    }
};

int main () {
    string a = "10", b = "11";
    Solution solution;
    solution.addBinary(a,b);
    // printf("%s\n",);
    return 0;
}