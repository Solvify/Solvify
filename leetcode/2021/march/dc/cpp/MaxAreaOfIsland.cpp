#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int area(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size())  return 0;
        if (grid[r][c] == 0)   return 0;

        grid[r][c] = 0;

        return 1 + area(grid, r - 1, c) + area(grid, r + 1, c) + area(grid, r, c - 1) + area(grid, r, c + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_Area = 0;
        for (int i(0); i < grid.size(); i++) {
            for (int j(0); j < grid[i].size(); j++) {
                if (grid[i][j] == 1)
                    max_Area = max(max_Area, area(grid, i, j));
            }
        }

        return max_Area;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid{ {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1} };
    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}