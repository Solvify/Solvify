#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();

        vector<vector<int>> dp(r,vector<int>(c));

        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1) {
            if(obstacleGrid[0][0]==1)   return 0;
            else return 1;
        }
        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==2) {
            if(obstacleGrid[0][0]==0 && obstacleGrid[0][1]==0)   return 1;
            else return 0;
        }
        if(obstacleGrid.size()==2 && obstacleGrid[0].size()==1) {
            if(obstacleGrid[0][0]==0 && obstacleGrid[1][0]==0)   return 1;
            else return 0;
        }
        if(obstacleGrid[r-1][c-1]==0) {
            if(obstacleGrid[r-2][c-1]==0)   dp[r-2][c-1] =1;
            else dp[r-2][c-1] =0;

            if(obstacleGrid[r-1][c-2]==0)   dp[r-1][c-2] =1;
            else dp[r-1][c-2] =0;
        } else {
            dp[r-2][c-1] =0;
            dp[r-1][c-2] =0;
        }

        for(int i=r-2; i>=0; --i) {
            for(int j=c-2; j>=0; --j) {
                if(obstacleGrid[i][j]==1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        //return dfs(m,n);
        return dp[0][0];
    }
};
int main() {
    Solution solution;
    vector<vector<int>> arr {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    cout<<solution.uniquePathsWithObstacles(arr);
    return 0;
}