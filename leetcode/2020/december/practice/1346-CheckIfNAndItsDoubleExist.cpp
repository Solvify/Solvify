#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // straight forword solution
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            for (int j = i + 1; j < arr.size(); j++)
                if (arr[i] == (2 * arr[j]) || (2 * arr[i]) == arr[j])
                    return true;
        return false;
    }
    // triky solution
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (int num : arr) {
            if (hash[num * 2] || (num % 2 == 0 && hash[num / 2]))
                return true;
            else
                hash[num]++;

        }
        return false;
    }



};

int main() {
    vector<int> arr{ 7,14 };
    Solution solution;
    cout << solution.checkIfExist(arr) << endl;
    return 0;
}