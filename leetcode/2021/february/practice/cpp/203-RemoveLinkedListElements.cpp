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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode temp(0, head);
        ListNode* curr = &temp;
        while (curr->next) {
            if (curr->next->val == val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return temp.next;
    }
};

void display(ListNode* list) {
    struct ListNode* ptr = list;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


int main() {
    Solution solution;
    ListNode six(2);
    ListNode five(5, &six);
    ListNode four(2, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(2, &two);

    display(solution.removeElements(&one, 2));
}

