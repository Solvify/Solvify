#include <iostream>
#include <vector>
#include <map>

using namespace std;
int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> in(N+1,0),out(N+1,0);

    for(auto& t: trust) {
        ++out[t[0]];
        ++in[t[1]];
    }
    for(int i=1; i<=N; i++) {
        if(in[i]==N-1 && out[i]==0) return i;
    }
    return -1;
}
int main() {
    int n=3;
    vector<vector<int>> trust {{1,3},{2,3},{3,1}};

    cout<<findJudge(n,trust);

    return 0;
}