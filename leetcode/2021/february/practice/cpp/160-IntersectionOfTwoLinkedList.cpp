#include<iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t=headA;
        while(t)
        {
            t->val=(t->val)*-1;
            t=t->next;
        }
        t=headB;
        while(t)
        {
            if(t->val<0)
                break;
            t=t->next;
        }
        ListNode *tmp=headA;
        while(tmp)
        {
            tmp->val=(tmp->val)*-1;
            tmp=tmp->next;
        }
        return t;
    }
};
int main()
{
    Solution solution;
    ListNode six(6);
    ListNode five(5, &six);
    ListNode four(4, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);
    ListNode eight(8, &three);
    ListNode seven(7, &eight);
    cout << solution.getIntersectionNode(&one, &seven)->val << endl;
    return 0;
}