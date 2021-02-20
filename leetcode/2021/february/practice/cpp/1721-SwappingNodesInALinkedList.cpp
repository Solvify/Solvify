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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head, * A, * B;
        while (curr) {
            len++;
            if (len == k)   A = curr;
            curr = curr->next;
        }
        curr = head;
        len = len - k;
        while (curr) {
            if (!len) {
                B = curr;
                break;
            }
            curr = curr->next;
            len--;
        }
        len = A->val;
        A->val = B->val;
        B->val = len;
        return head;
    }
};

int main() {
    Solution solution;
    ListNode five(5);
    ListNode four(4, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);

    display(solution.swapNodes(&one, 2));
}