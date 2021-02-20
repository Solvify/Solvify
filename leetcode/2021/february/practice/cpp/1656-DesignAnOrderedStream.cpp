#include<iostream>
#include<vector>

using namespace std;

class OrderedStream {
public:
    vector<string> strs;
    int ptr;
    OrderedStream(int n) {
        strs.resize(n);
        ptr = 0;
    }
    vector<string> insert(int id, string value) {
        vector<string> result;
        strs[id] = value;
        if (ptr == id) {
            while (ptr < strs.size()) {
                result.push_back(strs[ptr]);
                ptr++;
            }
        }
        return result;
    }


};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

void printVector(vector<string>& data) {
    for (string str : data)
        cout << str.c_str() << " ";
}

int main() {
    OrderedStream* obj = new OrderedStream(12);
    vector<string> data = obj->insert(12, "value");
    return 0;
}