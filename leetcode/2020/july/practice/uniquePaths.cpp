#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //recursion approach
    int dfs(int m, int n) {
        if(m==1 || n==1)    return 1;
        return dfs(m,n-1)+dfs(m-1,n);
    }

    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> dp(n,vector<int>(m,1));
        for(int i=n-2; i>=0; --i) {
            for(int j=m-2; j>=0; --j)
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
        }
        //return dfs(m,n);
        return dp[0][0];

    }
};
int main() {
    Solution solution;
    cout<<solution.uniquePaths(7,3);
    return 0;
}