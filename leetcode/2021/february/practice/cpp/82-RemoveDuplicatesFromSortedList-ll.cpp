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
        ListNode temp(0, head);
        ListNode* curr = &temp;
        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int dup = curr->next->val;
                while (curr->next && curr->next->val == dup)
                    curr->next = curr->next->next;
            } else
                curr = curr->next;
        }
        return temp.next;
    }
};


int main() {
    Solution solution;
    ListNode n3 = { 2 };
    ListNode n2 = { 1,&n3 };
    ListNode n1 = { 1,&n2 };
    display(solution.deleteDuplicates(&n1));
    return 0;
}