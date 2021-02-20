#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binary_search(vector<int> & a,int l,int r,int k) {
        cout<<"l : "<<l<<" r :"<<r<<endl;
        if(l>r) {
            return -1;
        }
        int m = l+(r-l)/2;
        if(m!=0 && ((a[m]==k) || (a[m-1]<k && a[m]>k))) {
            return m;
        }else if(a[m]>k) {
            return binary_search(a,l,m-1,k);
        } else {
            return binary_search(a,m+1,r,k);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int res = binary_search(nums,0,n-1,target);
        if(res==-1) {
            if(target <= nums[0])  return 0;
            else    return nums.size();
        } else {
            return res;
        }
    }
};
int main() {
   vector<int> v{1,3,5,6};
   Solution solution;
   cout<<solution.searchInsert(v,8)<<endl;
    return 0;
}