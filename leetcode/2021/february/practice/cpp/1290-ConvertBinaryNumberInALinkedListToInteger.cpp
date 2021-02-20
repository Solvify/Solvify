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
    int dfs(ListNode* head, int& index) {
        if (!head)   return 0;
        int res = dfs(head->next, index) + (head->val << index);
        index++;
        return res;
    }

    // With O(n) time and O(1) space
    int getDecimalValue(ListNode* head) {
        int index = 0;
        return dfs(head, index);
    }
    // With O(n) time and O(n) space
    int getDecimalValue(ListNode* head) {
        vector<int> nums;
        int ans = 0;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int size = nums.size() - 1;
        for (int i(size); i >= 0; i--)
            ans += (nums[i] << (size - i));

        return ans;
    }
};

int main() {
    Solution solution;
    ListNode n3 = { 0 };
    ListNode n2 = { 0,&n3 };
    ListNode n1 = { 1,&n2 };

    cout << solution.getDecimalValue(&n1) << endl;
}