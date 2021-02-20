#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0, curr = 0;
        for (int num : gain) {
            curr += num;
            if (highestAltitude < curr)
                highestAltitude = curr;
        }
        return highestAltitude;
    }
};

int main() {
    Solution solution;
    vector<int> gain{ -5,1,5,0,-7 };
    cout << solution.largestAltitude(gain) << endl;
    return 0;
}