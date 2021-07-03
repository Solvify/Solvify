#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        ListNode* curr = head;
        while (curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }

        int size = res.size();
        for (int i(size - 1); i >= 0; i--) {
            if (st.empty()) {
                st.push(res[i]);
                res[i] = 0;
            } else {
                int curr = res[i];
                while (!st.empty() && st.top() <= curr)   st.pop();
                if (st.empty())
                    res[i] = 0;
                else
                    res[i] = st.top();
                st.push(curr);
            }

        }
        return res;
    }
};


int main() {
    Solution solution;
    ListNode six(2);
    ListNode five(5, &six);
    ListNode four(2, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(2, &two);

    for (int num : solution.nextLargerNodes(&one)) {
        cout << num << " ";
    }
}

