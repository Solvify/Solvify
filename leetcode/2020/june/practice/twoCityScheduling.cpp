#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return (a[0]-a[1]) < (b[0]-b[1]);
    }
    static int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum =0;
        sort(costs.begin(),costs.end(),cmp);
        int n=costs.size()/2;
        for(auto & x: costs) {
            if(n>0) {
                sum+=x[0];
                --n;
            } else {
                sum+=x[1];
            }
        }
        return sum;
    }
};
int main() {
    vector<vector<int>> v {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};//{{10,20},{30,200},{400,50},{30,20}};
    Solution solution;
    cout<< solution.twoCitySchedCost(v)<<endl;
    return 0;
}