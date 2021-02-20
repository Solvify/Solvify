#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> element_index_map;
    vector<int> arr;
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(element_index_map.find(val)!=element_index_map.end())
            return false;

        arr.push_back(val);
        element_index_map[val] = arr.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(element_index_map.find(val)==element_index_map.end())
            return false;


        auto it = element_index_map.find(val);
        arr[it->second] = arr.back();
        arr.pop_back();
        element_index_map[arr[it->second]] = it->second;
        element_index_map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {
    RandomizedSet randomizedSet;

//    cout<<randomizedSet.getRandom()<<endl;
    cout<<randomizedSet.insert(1)<<endl;
    cout<<randomizedSet.remove(2)<<endl;
    cout<<randomizedSet.insert(2)<<endl;
    cout<<randomizedSet.getRandom()<<endl;
    cout<<randomizedSet.remove(1)<<endl;
    cout<<randomizedSet.insert(2)<<endl;
    cout<<randomizedSet.getRandom()<<endl;

    return 0;
}