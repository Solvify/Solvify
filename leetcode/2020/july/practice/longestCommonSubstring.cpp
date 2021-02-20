#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int longest_common_substring_len(string s1, string s2) {
    //brute force approach
    int max = 0;
    string  res;
    for(int i=1; i<s2.length(); i++) {
        for(int j=0; j<s2.length()-i+1; j++) {
            string  sub_s = s2.substr(j,i);
            string pattern = "(.*)"+sub_s+"(.*)";
            regex r (pattern);
            //cout<<"substr : "<<sub_s<<" pattern : "<<"is matched : "<<pattern<<regex_match(s1,r)<<endl;
            if(regex_match(s1,r)) {
                cout<<"max : "<<max<<" len : "<<sub_s.length()<<endl;
                if(max < sub_s.length()) {
                    max = sub_s.length();
                    res = sub_s;
                }
            }
        }
    }

    cout<<res<<endl;

    return max;

}
int main() {
    string s1 = "abbacxdfghjabaok";
    string s2 = "lodfghjaab";
/*    regex temp("([a-z]*)[aa]([a-z]*)");
    cout<<regex_match(s1,temp);*/
    cout<<longest_common_substring_len(s2,s1)<<endl;
    return 0;
}