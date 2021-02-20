#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board,int i, int j) {
        cout<<"i : "<<i<<" j : "<<j<<endl;
        if(board[i][j]=='O'){
            board[i][j] = '1';

            if(i+1 < board.size())    dfs(board,i+1,j);
            if(i > 1 )    dfs(board,i-1,j);
            if(j+1 < board[i].size())    dfs(board,i,j+1);
            if(j > 1)    dfs(board,i,j-1);
        }
    }
    void solve(vector<vector<char>>& board) {

        if(board.empty()) return;

        int row = board.size(),col = board[0].size();

        for(int i=0; i<row; i++) {
            dfs(board,i,0);
            dfs(board,i,col-1);
        }

        for(int j=0; j<col; j++) {
            dfs(board,0,j);
            dfs(board,row-1,j);
        }
        for(auto & i : board){
            for(char & j : i){
                if(j=='O')    j = 'X';
                if(j=='1')    j = 'O';
            }
        }

        for(auto & x: board){
            for(char c : x){
                cout<<c<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
    Solution solution;
    vector<vector<char>> board {
        /*{'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}*/
            {'O', 'X', 'X', 'O', 'X'},
            {'X', 'O', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'O', 'O'},
            {'X', 'X', 'O', 'X', 'O'}
    };

    /*[["O","X","X","O","X"],
     ["X","O","O","X","O"],
     ["X","O","X","O","X"],
     ["O","X","O","O","O"],
     ["X","X","O","X","O"]]
    [["O","X","X","O","X"],
     ["X","X","X","X","O"],
     ["X","X","X","X","X"],
     ["O","X","O","O","O"],
     ["X","X","O","X","O"]]
    [["O","X","X","O","X"],
     ["X","X","X","X","O"],
     ["X","X","X","O","X"],
     ["O","X","O","O","O"],
     ["X","X","O","X","O"]]*/

    solution.solve(board);


    return 0;
}