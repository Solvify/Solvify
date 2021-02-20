#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //O(n2) solution
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        for (int i = 0; i < time.size() - 1; i++) {
            for (int j = i + 1; j < time.size(); j++) {
                if ((time[i] + time[j]) % 60 == 0) {
                    count++;
                }
            }
        }
        return count;
    }

    int numPairsDivisibleBy60(vector<int>& time) {
        int lenght = time.size(), freq[60] = { 0 };
        for (int i = 0; i < lenght; i++) freq[time[i] % 60]++;
        int count = freq[0] * (freq[0] - 1) / 2;
        for (int i = 1; i <= 60 / 2 && i != (60 - i); i++) count += freq[i] * freq[60 - i];
        if (60 % 2 == 0) count += (freq[60 / 2] * (freq[60 / 2] - 1) / 2);
        return count;
    }

    // Perfact Solution
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> s(60, 0);
        for (int i = 0; i < time.size(); i++)         {
            int w = time[i] % 60;
            if (w == 0) count += s[w];
            else count += s[60 - w];
            s[w]++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> arr{ 30,20,150,100,40 };
    cout << solution.numPairsDivisibleBy60(arr) << endl;
    return 0;
}