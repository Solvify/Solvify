#include <iostream>
#include <vector>
using namespace std;

// My solution
/*class Solution {
public:
    int singleNonDuplicateUtil(int arr[],int start, int end) {
        //cout<<"start : "<<start<<" End : "<<end<<endl;
        if (start <= end){
            int mid = start + (end - start) / 2;
            if (arr[mid] != arr[mid+1] && arr[mid]!=arr[mid-1])
                return mid;
            if (arr[mid] == arr[mid-1] && mid%2==0)
                return singleNonDuplicateUtil(arr, start, mid - 1);
            if (arr[mid] == arr[mid-1] && mid%2==1)
                return singleNonDuplicateUtil(arr, mid+1, end);
            if (arr[mid] == arr[mid+1] && mid%2==0)
                return singleNonDuplicateUtil(arr, mid+1, end);
            if (arr[mid] == arr[mid+1] && mid%2==1)
                return singleNonDuplicateUtil(arr, start, mid - 1);
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int *arr = new int[nums.size()];
        for(int i=0;i<nums.size(); i++) {
            arr[i] = nums[i];
        }
        int end = (int)nums.size()-1,start =0;
        return singleNonDuplicateUtil(arr,start,end);
    }
};*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start =0, end =nums.size()-1;

        while(start<=end) {
            int mid = start +(end-start)/2;
            if(start==end) {
                return nums[start];
            } else if(mid%2==0) {
                if(nums[mid]==nums[mid+1]) {
                    start = mid+2;
                } else {
                    end = mid;
                }
            } else {
                if(nums[mid] == nums[mid-1]) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};
int main() {
    vector<int> arr {3,3,7,7,9,10,10,11,11,12,12};
    Solution solution;
    cout<<solution.singleNonDuplicate(arr);

    return 0;
}