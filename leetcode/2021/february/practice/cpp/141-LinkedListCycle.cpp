#include<iostream>


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
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* slow = head, * fast = head->next;

        while (fast && fast->next) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};


int main() {
    Solution solution;
    ListNode four(-4);
    ListNode zero(0, &four);
    ListNode two(2, &zero);
    ListNode three(3, &two);
    four.next = &two;

    cout << solution.hasCycle(&two) << endl;

}