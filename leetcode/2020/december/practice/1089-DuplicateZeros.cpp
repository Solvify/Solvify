#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        int count=0;
        for(int num : arr) {
            if(num==0) {
                ans.push_back(0);
                count++;
            }
            ans.push_back(num);
        }
        while (count--){
           ans.pop_back();
        }
        arr = move(ans);
    }
};

int main () {
    vector<int> arr{1,0,2,0,3,4,5,0};
    Solution solution;
    solution.duplicateZeros(arr);
    for(int num : arr) {
        cout << num << " ";
    }
    return 0;
}