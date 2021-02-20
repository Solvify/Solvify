#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int i, int j) { return (i % 2 == 0); }

struct Comp {
    bool operator() (int i, int j) { return (i % 2 == 0); }
} obj;

class Solution {
public:
    // with extra space
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> evens, odds;
        for (int num : A)
            if (num % 2 == 0)
                evens.push_back(num);
            else
                odds.push_back(num);
        for (int odd : odds)
            evens.push_back(odd);
        return evens;
    }
    // O(1) space compplexity and O(nlogn)
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), comp);
        return A;
    }
    // perfact solution with O(1) space and O(n) time 
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size(), l = 0, r = n - 1;
        while (l < r) {
            if (A[l] % 2 != 0 & A[r] % 2 == 0) {
                swap(A[l], A[r]);l++;r--;
            } else if (A[l] % 2 == 0 & A[r] % 2 == 0)
                l++;
            else if (A[l] % 2 != 0 & A[r] % 2 != 0)
                r--;
            else {
                l++;
                r--;
            }
        }
        return A;
    }

};

int main() {
    vector<int> A{ 3363,4833,290,3381,4227,1711,1253,2984,2212,874,2358,2049,2846,2543,1557,1786,4189,1254,2803,62,3708,1679,228,1404,1200,4766,1761,1439,1796,4735,3169,3106,3578,1940,2072,3254,7,961,1672,1197,3187,1893,4377,2841,2072,2011,3509,2091,3311,233 };
    Solution solution;
    A = solution.sortArrayByParity(A);;
    for (int num : A)  cout << num << " ";
    return 0;
}