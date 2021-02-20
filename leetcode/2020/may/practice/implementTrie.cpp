#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    static int cmp(pair<int,int> a,pair<int,int> b) {
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
    }
};
int main() {


    std::cout << "Hello, World!" << std::endl;

    string s = "zzzyyyvvssskkkhhppsqqpxxnaabboossddllllh";
    Solution solution;

    cout<<solution.frequencySort(s)<<endl;
}