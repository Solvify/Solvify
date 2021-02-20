#include <iostream>
#include <unordered_map>

using namespace std;
int main() {
    unordered_map<int,int> mp;
    mp[2]++;
    mp[5]++;
    mp[7]++;

    if(mp.find(8)!=mp.end()) {
        cout<<"founded !";
    } else {
        cout<<"Not found !";
    }
    return 0;
}