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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode temp(0, list1);
        ListNode* start, * end, * curr = &temp;
        while (curr->next) {
            if (!(a--))
                start = curr;
            if (!(b--))
                end = curr->next->next;
            curr = curr->next;
        }
        if (end)
            curr = list2;
        ListNode* list2_end;
        while (curr) {
            if (!curr->next)
                list2_end = curr;

            curr = curr->next;
        }
        start->next = list2;
        list2_end->next = end;
        return temp.next;
    }

    // Claver Solution
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1 = list1, * head2 = list2;
        ListNode* removeHead;
        int i = 0, j = 0;
        while (i++ < b) {
            if (j++ < a)
                removeHead = list1;
            list1 = list1->next;
        }
        while (list2->next != nullptr)
            list2 = list2->next;
        removeHead->next = head2;
        list2->next = list1->next;
        return head1;
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
    ListNode four(4);
    ListNode zero(0, &four);
    ListNode two(2, &zero);
    ListNode three(3, &two);

    ListNode hundred(100);
    ListNode hundred_one(101, &hundred);
    ListNode hundred_two(102, &hundred_one);
    ListNode hundred_three(103, &hundred_two);

    display(solution.mergeInBetween(&three, 0, 3, &hundred_three));
}