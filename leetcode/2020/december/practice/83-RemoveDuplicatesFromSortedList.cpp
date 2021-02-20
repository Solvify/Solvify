#include<iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void display(ListNode* list) {
    struct ListNode* ptr = list;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head, * curr = head;
        while (curr) {
            if (curr->val != prev->val) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        if (prev != curr)
            prev->next = nullptr;

        return head;
    }
    // better solution
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};


int main() {
    Solution solution;
    ListNode n3 = { 4 };
    ListNode n2 = { 2,&n3 };
    ListNode n1 = { 1,&n2 };
    display(solution.deleteDuplicates(&n1));
    return 0;
}