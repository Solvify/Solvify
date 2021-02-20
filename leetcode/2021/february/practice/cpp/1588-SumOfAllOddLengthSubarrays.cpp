#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // Basic O(n2) solution
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), sum = 0, temp;

        for (int i(0); i < n; i++) {
            temp = 0;
            for (int j(i); j < n; j++) {
                temp += arr[j];
                if ((j - i) % 2 == 0) {
                    sum += temp;
                }
            }
        }
        return sum;
    }
    // O(n) solution
    int sumOddLengthSubarrays(vector<int>& arr) {
        double start, end, sum = 0;
        for (int i(0); i < arr.size(); i++) {
            start = arr.size() - i;
            end = i + 1;
            double pro = ceil((start * end) / 2) * arr[i];
            sum += pro;
        }
        return int(sum);
    }
};

int main() {
    Solution solution;
    vector<int> arr{ 10,11,12 };
    cout << solution.sumOddLengthSubarrays(arr) << endl;
    return 0;
}