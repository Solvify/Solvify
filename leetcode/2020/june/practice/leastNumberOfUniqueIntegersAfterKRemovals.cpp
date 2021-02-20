#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    static bool cmp(pair<int,int> p1,pair<int,int> p2) {
        return p1.second < p2.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(int & x :arr)   ++mp[x];

        vector<pair<int,int>> v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),cmp);

        int map_size = mp.size();
        int no_of_item_removed=0;
        for(auto x : v) {
            cout<<x.first<< " ==>"<<x.second<<endl;
            if(k > no_of_item_removed) {
                cout<< no_of_item_removed <<" "<<k <<endl;
                if(abs(k-no_of_item_removed)>=x.second) {
                    no_of_item_removed += x.second;
                    --map_size;
                } else {
                    break;
                }

            } else {
                break;
            }

        }

        return map_size;

    }
};
int main() {
    vector<int> v{2,4,1,8,3,5,1,3};
    Solution solution;
    std::cout << solution.findLeastNumOfUniqueInts(v,3) << std::endl;
    return 0;
}