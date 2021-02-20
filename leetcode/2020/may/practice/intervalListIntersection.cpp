#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> v;
        int a_i=0,b_i=0,j=0,a_size = A.size(),b_size = B.size();
        while (a_i < a_size && b_i < b_size) {
//            cout<<"A is : "<<A[a_i][j]<<" "<<A[a_i][j+1]<<endl;
//            cout<<"B is : "<<B[b_i][j]<<" "<<B[b_i][j+1]<<endl;
            if(B[b_i][j+1] >= A[a_i][j] && B[b_i][j]<= A[a_i][j+1]) {
                vector<int> temp;
//                cout<<"Max : "<<max(B[b_i][j],A[a_i][j])<<endl;
//                cout<<"Min : "<<min(B[b_i][j+1],A[a_i][j+1])<<endl;
                temp.push_back(max(B[b_i][j],A[a_i][j]));
                temp.push_back(min(B[b_i][j+1],A[a_i][j+1]));
                v.push_back(temp);
            }
            if(A.at(a_i).at(j+1)<B.at(b_i).at(j+1)) {
                a_i++;
            } else {
                b_i++;
            }
        }

        return v;
    }
};
int main() {
    vector<vector<int>> A {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B {{1,5},{8,12},{15,24},{25,26}};
    Solution solution;
    vector<vector<int>> res = solution.intervalIntersection(A,B);
    for( auto& i : res) {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}