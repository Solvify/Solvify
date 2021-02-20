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
    // Itrative approch
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, * prev = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* dfs(ListNode* curr, ListNode* prev) {
        if (!curr)
            return prev;
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        return dfs(curr, prev);
    }
    // Recursive approch
    ListNode* reverseList(ListNode* head) {
        return dfs(head, nullptr);
    }
};


int main() {
    Solution solution;
    ListNode six(6);
    ListNode five(5, &six);
    ListNode four(4, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);

    display(solution.reverseList(&one));
}