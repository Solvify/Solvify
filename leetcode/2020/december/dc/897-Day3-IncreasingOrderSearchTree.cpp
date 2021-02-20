#include<iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }
    void inorder(TreeNode* root, TreeNode* prev) {
        if (root->left != nullptr)
            inorder(root->left, prev);
        prev->right = root;
        prev = prev->right;
        if (root->right != nullptr)
            inorder(root->right, prev);

    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp = new TreeNode();
        TreeNode* prev = temp;
        inorder(root, prev);
        prev->left = nullptr;
        prev->right = nullptr;
        TreeNode* res = temp->right;
        delete temp;
        return res;
    }
};

void display(TreeNode* root) {
    struct TreeNode* ptr = root;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->right;
    }
    cout << endl;
}

int main() {

    Solution solution;
    TreeNode l(1);
    TreeNode r(7);
    TreeNode n(5, &l, &r);
    display(solution.increasingBST(&n));

    return 0;
}