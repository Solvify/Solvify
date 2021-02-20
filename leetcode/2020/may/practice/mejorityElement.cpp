#include <iostream>
#include <vector>
#include <map>


using namespace std;
int main() {
    vector<int> arr = {2,2,1,1,1,2,2};
    int size=0;
    map<int, int> my_map;
    for(int num: arr){
        ++my_map[num];
        ++size;
    }
    for (auto& x: my_map)   if(x.second > (size/2)) cout<<x.first;
    return 0;
}