#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(),n = dungeon[0].size();
        for(int i=m-1; i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                if(i==m-1 && j==n-1) {
                    dungeon[i][j] = min(0,dungeon[i][j]);
                } else if(i==m-1) {
                    dungeon[i][j] = min(0,dungeon[i][j]+dungeon[i][j+1]);
                } else if(j==n-1) {
                    dungeon[i][j] = min(0,dungeon[i][j]+dungeon[i+1][j]);
                } else {
                    dungeon[i][j] = min(0,dungeon[i][j]+ max(dungeon[i][j+1],dungeon[i+1][j]));
                }
            }
        }
        return abs(dungeon[0][0]) +1;
    }
};
int main() {
    vector<vector<int>> v {{0},{1}};//{{-200}};

    Solution solution;
    cout<<solution.calculateMinimumHP(v);
    return 0;
}