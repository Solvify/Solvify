#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // for faster io oprations
    Solution() {
		ios_base::sync_with_stdio(false); cin.tie(NULL);
	}
    bool validMountainArray(vector<int>& arr) {
        auto len = arr.size();
        auto i=0,j=1,k=2,is_peak_occur=0;
        if(len < 3)    return false;
        while (k<len)   {
            if(((arr[j] > arr[i]) && (arr[j] > arr[k]))) is_peak_occur = 1;
            if(!(((arr[j] > arr[i]) && (arr[j] < arr[k])) || ((arr[j] < arr[i]) && (arr[j] > arr[k])) || ((arr[j] > arr[i]) && (arr[j] > arr[k])))) {
               return false;
            }
            i++;j++;k++;
        }
        return is_peak_occur && !((arr[j-1] > arr[i-1]) && (arr[j-1] < arr[k-1]));
    }
};

int main() {
    Solution solution;
    vector<int> arr{1,2,3,3,2,1};
    cout << solution.validMountainArray(arr) << endl;
    return 0;
}