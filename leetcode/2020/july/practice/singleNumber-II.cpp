#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //by using map with time complexity O(n) & space complexity O(n);
    /*int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,int> nums_with_frq;
        for(int & i : nums) ++nums_with_frq[i];
        for(auto & x : nums_with_frq){
            if(x.second==1)
                return x.first;
        }
        return -1;
    }*/
    //by using bit manipulation with time complexity O(n) & space complexity O(1);
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int ones = 0,twos = 0;
        for(int & i : nums) {
            ones = (i^ones) & (~twos);
            twos = (i^twos) & (~ones);
            cout<<"ones : "<<ones<<" twos : "<<twos<<endl;
        }
        return ones;
    }
};
int main() {
    vector<int> arr {0,1,0,1,0,1,99};
    Solution solution;

    cout<<solution.singleNumber(arr);
    return 0;
}