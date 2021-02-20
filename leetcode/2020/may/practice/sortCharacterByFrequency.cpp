#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    //my Solution
    /*static int cmp(pair<int,int> a,pair<int,int> b) {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int> mp;
        for(char c: s)  mp[c]++;
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        string res;
        for(auto & y : v)   res+=string (y.second,y.first);
        return res;
    }*/
    // Fantastic solution
    string frequencySort(const string& s) {
       vector<pair<int,char>> v('z'+1,{0,0});
        for(char c: s) {
            v[c] = {v[c].first+1,c};
        }
        sort(v.begin(),v.end());
        string res;
        for(auto & y : v)   res=string (y.first,y.second)+res;
        return res;
    }

};
int main() {
    string s = "zzzyyyvvssskkkhhppsqqpxxnaabboossddllllh";
    Solution solution;

    cout<<solution.frequencySort(s)<<endl;
}