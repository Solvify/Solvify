#include<iostream>
#include<vector>

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
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode* curr = head;
        int count = 0, size = G.size();
        if (size == 1) return 1;
        while (curr->next) {
            int start = curr->val, end = curr->next->val, index;
            for (int i = 0; i < size; i++) {
                if (G[i] == start) index = i;
                if (G[i] == end) {
                    if (index < i) {
                        count++;
                    }
                }
            }
            curr = curr->next;
        }
        return count;
    }
};


int main() {
    Solution solution;
    // ListNode six(2);
    // ListNode five(5, &six);
    // ListNode four(4, &five);
    ListNode three(3);
    ListNode two(2, &three);
    ListNode one(1, &two);
    ListNode zero(0, &one);
    vector<int> G{ 0,1,3 };
    cout << solution.numComponents(&zero, G) << " ";
    return 0;
}

