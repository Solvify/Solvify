#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static void floodFillRecursive(vector<vector<int>>& image, int i, int j,int old_color, int new_color) {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=old_color) {
            return;
        }
        image[i][j] = new_color;
        floodFillRecursive(image,i+1,j,old_color,new_color);
        floodFillRecursive(image,i-1,j,old_color,new_color);
        floodFillRecursive(image,i,j+1,old_color,new_color);
        floodFillRecursive(image,i,j-1,old_color,new_color);
    }
    static vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old_color = image[sr][sc];

        if(newColor!=old_color) {
            floodFillRecursive(image,sr,sc,old_color,newColor);
        }
        return image;

    }
};
int main() {
    vector<vector<int>> image {
            {1,1,1},
            {1,1,0},
            {1,0,1}
    };
    Solution solution;
    image = solution.floodFill(image,1,1,5);

    for(auto & i:image) {
        for(auto & j: i) {
            cout<< j<<" ";
        }
        cout<<endl;
    }

    return 0;
}