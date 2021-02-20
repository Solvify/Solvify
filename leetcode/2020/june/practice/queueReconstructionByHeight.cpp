#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0]!=b[0]) {
            return a[0]<b[0];
        } else {
            return a[1]<b[1];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),cmp);

        for(const auto & x: people) {
            cout<<"{"<<x[0]<<", "<<x[1]<<"}, ";
        }
        cout<<endl;
        vector<vector<int> > res(n , vector<int> (2, -1));
        for(int i=0; i<n; ++i) {
            int count = people[i][1];
            for(int j=0; j<n; ++j) {
                if(res[j][0]==-1 && count==0) {
                    res[j][0] = people[i][0];
                    res[j][1] = people[i][1];
                    break;
                } else if(res[j][0]==-1 || res[j][0]>=people[i][0]) {
                    --count;
                }
            }
        }

        return res;
    }
};
int main() {
    vector<vector<int>> v{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution solution;
    for(const auto & x: solution.reconstructQueue(v)) {
        cout<<"{"<<x[0]<<", "<<x[1]<<"}, ";
    }
    return 0;
}