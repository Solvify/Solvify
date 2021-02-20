#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void reverseString(vector<char>& s) {
        int l=0, r= s.size()-1;
        while (l<r) {
            s[l] = s[l]+s[r];
            s[r] = s[l]-s[r];
            s[l] = s[l]-s[r];
            ++l;
            --r;
        }
        cout<<"after reverse : ";
        for(char ch : s) cout<<ch<<" ";

    }
};
int main() {
    vector<char> v{'h','e','l','l'};
    cout<<"before reverse : ";
    for(char ch : v) cout<<ch<<" ";
    cout<<endl;
    Solution::reverseString(v);
    return 0;
}