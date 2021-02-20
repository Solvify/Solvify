#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max=INT32_MIN;
        for(int candy : candies) if(max < candy) max = candy;

        for(int i=0; i < candies.size(); i++) {
            if ((candies[i] + extraCandies)>=max) {
                candies[i] = true;
            } else {
               candies[i] = false;
            } 
        }
        
        return candies;
    }
};

int main() {
    vector<int> candies = { 2, 3, 5, 1, 3 };
    int extCandies = 3;
    Solution solution;
    vector<int> res = solution.kidsWithCandies(candies,extCandies);
    for(bool it: res ) {
        cout<<it<<", ";
    }
    
    
}