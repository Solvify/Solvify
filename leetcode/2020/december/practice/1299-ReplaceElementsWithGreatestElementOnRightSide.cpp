#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size =arr.size(),max = arr[size-1];
        arr[size-1] = -1;
        for(int i=size-2; i>=0; i--) {
            int new_max = max;
            if(arr[i]>new_max)  new_max = arr[i];
            arr[i] = max;
            max = new_max;
        } 
        return arr;
    }
};

int main() {
    vector<int> arr{17};
    Solution solution;
    arr = solution.replaceElements(arr);
    for(int num: arr)   cout <<num <<" ";
    return 0;
}