#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &v1, vector<int> & v2) {
    return v1.size() > v2.size();
}
vector< vector<int> > getAllSubsets(vector<int> set) {
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back( empty );

    for (int i : set) {
        vector< vector<int> > subsetTemp = subset;  //making a copy of given 2-d vector.

        for (auto & j : subsetTemp)
            j.push_back( i );   // adding set[i] element to each subset of subsetTemp. like adding {2}(in 2nd iteration  to {{},{1}} which gives {{2},{1,2}}.

        for (const auto & j : subsetTemp)
            subset.push_back( j );  //now adding modified subsetTemp to original subset (before{{},{1}} , after{{},{1},{2},{1,2}})
    }
    return subset;
}
int main() {
    vector<int> v{3,2,4};
    auto res = getAllSubsets(v);
    for(const auto& x:res) {
        for(int y: x) {
            cout<<y <<" ";
        }
        cout<<endl;
    }
    sort(res.begin(),res.end(),cmp);

    for(const auto& x:res) {
        for(int y: x) {
            cout<<y <<" ";
        }
        cout<<endl;
    }

    return 0;
}