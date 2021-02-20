#include <iostream>
using namespace std;
class Solution {
public:
    static int check_next_vowel_from_left(string s,int l) {
        for (; l<s.size(); l++) {
            if(s[l]=='a' || s[l]=='e'|| s[l]=='i' || s[l]=='o' || s[l]=='u' || s[l]=='A' || s[l]=='E'|| s[l]=='I' || s[l]=='O' || s[l]=='U') {
                break;
            }
        }
        return l;
    }
    static int check_next_vowel_from_right(string s,int r) {
        for (; r>=0; r--) {
            if(s[r]=='a' || s[r]=='e'|| s[r]=='i' || s[r]=='o' || s[r]=='u' || s[r]=='A' || s[r]=='E'|| s[r]=='I' || s[r]=='O' || s[r]=='U') {
                break;
            }
        }
        return r;
    }
    static string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        while (l<r) {
             l  = check_next_vowel_from_left(s,l);
             r  = check_next_vowel_from_right(s,r);
             if(l>r) break;
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            ++l;
            --r;
        }
        return s;
    }
};
int main() {
    cout << Solution::reverseVowels("aA") <<endl;
    return 0;
}