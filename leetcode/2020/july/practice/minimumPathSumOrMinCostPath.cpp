#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int r=grid.size();
        if(r==0)    return 0;
        int c= grid[0].size();
        for(int i=1; i<c; ++i)
            grid[0][i] = grid[0][i-1]+grid[0][i];

        for(int i=1; i<r; ++i)
            grid[i][0] = grid[i-1][0]+grid[i][0];

        for(int i=1; i<r; ++i) {
            for(int j=1; j<c; ++j)
                grid[i][j] = grid[i][j]+min(grid[i][j-1],grid[i-1][j]);
        }
        return grid[r-1][c-1];
    }
};
int main() {
    vector<vector<int>> mat {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };

    Solution solution;

    cout<<solution.minPathSum(mat)<<endl;

    return 0;
}