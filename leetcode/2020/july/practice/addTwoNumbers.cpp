#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *list1,*list2;
void insert(int new_data,int flag) {
    auto* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = new_data;
    if(flag) {
        new_node->next = list1;
        list1 = new_node;
    } else {
        new_node->next = list2;
        list2 = new_node;
    }

}
void display(int flag) {
    struct ListNode* ptr;
    (flag) ? ptr = list1: ptr = list2;
    while (ptr != nullptr) {
        cout<< ptr->val <<" ";
        ptr = ptr->next;
    }
}

void display(ListNode *list) {
    struct ListNode* ptr = list;
    while (ptr != nullptr) {
        cout<< ptr->val <<" ";
        ptr = ptr->next;
    }
}

class Solution {
public:
    static ListNode * insert (ListNode *ptr, int sum) {
        auto* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = sum%10;
        new_node->next = nullptr;
        if(ptr== nullptr) {
            ptr = new_node;
        } else {
            ptr->next = new_node;
            ptr = ptr->next;
        }
        return ptr;
    }
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *result = nullptr;
        ListNode *ptr = result;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val+carry;
            if(ptr== nullptr) {
                ptr = insert(ptr,sum);
                result = ptr;
            } else {
                ptr = insert(ptr,sum);
            }
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int sum = l1->val +carry;
            if(ptr== nullptr) {
                ptr = insert(ptr,sum);
                result = ptr;
            } else {
                ptr = insert(ptr,sum);
            }
            carry = sum/10;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int sum = l2->val+carry;
            if(ptr== nullptr) {
                ptr = insert(ptr,sum);
                result = ptr;
            } else {
                ptr = insert(ptr,sum);
            }
            carry = sum/10;
            l2 = l2->next;
        }
        delete ptr;
        return result;
    }
};

int main() {
    insert(3,1);
    insert(4,1);
    insert(2,1);

    insert(4,0);
    insert(6,0);
    insert(5,0);
    cout<<"The linked list is l1 : ";
    display(1);
    cout<<endl;
    cout<<"The linked list is l1 : ";
    display(0);
    cout<<endl;
    ListNode *res = Solution::addTwoNumbers(list1,list2);
    display(res);


    return 0;
}