#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *head = nullptr;
ListNode *itr = nullptr;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head== nullptr) {
            return nullptr;
        } else {
            ListNode *odd = head, *even = head->next;
            ListNode *even_head = even;
            while (even != nullptr && even->next != nullptr) {
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
            odd->next = even_head;
            while (head!= nullptr) {
                cout<<head->val<<" ";
                head = head->next;
            }
        }
    }
};
int main()  {

    for(int i=5; i<50; i=i+5) {
        auto *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
        temp->val = i;
        if(head == nullptr) {
            head = temp;
            itr = temp;
        }else{
            struct ListNode* ghakkas;
            ghakkas = head;
            while(ghakkas->next != nullptr)
            {
                ghakkas = ghakkas->next;
            }
            ghakkas->next = temp;
        }
    }
    cout<<"Before the LinkedList ";
    while (itr!= nullptr) {
        cout<<itr->val<<" ";
        itr = itr->next;
    }
    cout<<endl;
    Solution solution;
    solution.oddEvenList(head);
}