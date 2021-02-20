#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 void display(ListNode *list) {
    struct ListNode* ptr = list;
    while (ptr != nullptr) {
        cout<< ptr->val <<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void move_node(ListNode** destRef, ListNode** sourceRef)  {  
    ListNode* newNode = *sourceRef;  
    if(newNode != nullptr) {
        *sourceRef = newNode->next;  
        newNode->next = *destRef;  
        *destRef = newNode;  
    } 
    
}  

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode res;
       ListNode* itr = &res;
       itr->next = nullptr;

        while (1)  {  
            if (l1 == nullptr)  {  
                itr->next = l2;  
                break;  
            }else if (l2 == nullptr)  {  
                itr->next = l1;  
                break;  
            }  
            if (l1->val <= l2->val)  
                move_node(&(itr->next), &l1);  
            else
                move_node(&(itr->next), &l2);  
    
            itr = itr->next;  
        }

        return (res.next);  

    }
};




int main() {
   
   ListNode n3 = {4};
   ListNode n2 = {2,&n3};
   ListNode n1 = {1,&n2};

   ListNode n6 = {4};
   ListNode n5 = {3,&n6};
   ListNode n4 = {1,&n5};
   
   display(&n1);
   display(&n4);
   cout << "-----------------" << endl;
   
   Solution solution;
   display(solution.mergeTwoLists(&n1,&n4));
   return 0;
}