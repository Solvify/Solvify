#include<iostream>
#include<vector>

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

    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = ans;
            ans = head;
            head = temp;
        }
        return ans;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //with O(n) time and O(n) space
    bool isPalindrome(ListNode* head) {
        if (!head)   return true;
        vector<ListNode*> arr;
        ListNode* curr = head;
        while (curr) {
            arr.push_back(curr);
            curr = curr->next;
        }
        int size = arr.size() - 1;
        for (int i = 0; i <= size / 2; i++) {
            if (arr[i]->val != arr[size - i]->val)
                return false;
        }
        return true;
    }

    //with O(n) time and O(1) space 
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)   return true;

        ListNode* middle = middleNode(head);
        ListNode* rev = reverseList(middle);
        while (rev && head) {
            if (head->val != rev->val)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};

int main() {
    Solution solution;
    ListNode three2(3);
    ListNode two2(2, &three2);
    ListNode two(2, &two2);
    ListNode three(3, &two);

    cout << solution.isPalindrome(&three) << endl;

}