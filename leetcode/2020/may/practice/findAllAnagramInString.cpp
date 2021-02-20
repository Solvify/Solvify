#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    //basic approach
/*    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int step = p.size();
        if(s.size()<p.size()) {
            return result;
        }
        sort(p.begin(),p.end());
        for(int i=0; i<s.size()-(step-1); i++){
            string substr = s.substr(i,step);
            sort(substr.begin(),substr.end());
            if(p == substr) {
                result.push_back(i);
            }
        }
        return result;
    }*/
    /*vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size()<p.size())    return result;
        vector<int> frq_p('z'+1,{0});
        for(char c: p)  ++frq_p[c];
        int step = p.size();
        for(int i=0; i<s.size()-(step-1); i++){
            vector<int> frq_sub('z'+1,{0});
            string substr = s.substr(i,step);
            for(char c: substr) ++frq_sub[c];
            int count=0,no_of_different_char_in_sub =0;
            for(int j=96; j<123; j++) {
                if(frq_sub[j]!=0) ++no_of_different_char_in_sub;
                if(frq_p[j]!=0 && frq_sub[j]!=0) {
                    if(frq_p[j]==frq_sub[j]) {
                        ++count;
                    }
                }
            }
            if(count==no_of_different_char_in_sub) result.push_back(i);
        }
        return result;
    }*/

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        map<char,int> mp,mp_copy;
        for(char c : p) ++mp[c];
        mp_copy = mp;
        int size = p.size(),size_copy=p.size();
        int index=0;
        for(char c : s) {
            if(mp_copy[c]>0) {
                --mp_copy[c];
                cout<<"reduce map"<<endl;
            }
            if(mp_copy[c]==0)  {
                --size_copy;
            }


            if(size_copy==0) {
                cout<<"all character matched"<<endl;
                result.push_back(index-(size-1));
                size_copy = size;
                mp_copy = mp;
            }
            ++index;
        }
        return result;
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    string s = "cbaebabacd",p = "abc";
    Solution solution;
    for(auto x : solution.findAnagrams(s,p)) {
        cout<<x<<" ";
    }
    return 0;
}