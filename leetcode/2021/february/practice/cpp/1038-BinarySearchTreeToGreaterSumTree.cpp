#include<iostream>
#include<vector>

using namespace std;


//  Definition for a binary tree node.
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

    int inorder(TreeNode* root, int sum) {
        if (!root)   return sum;
        root->val = sum = root->val + inorder(root->right, sum);
        return inorder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorder(root, 0);
        return root;
    }

    void printBST(TreeNode* root) {
        if (root->left)
            printBST(root->left);
        cout << root->val << " ";
        if (root->right)
            printBST(root->right);
    }
};


int main() {
    Solution solution;
    TreeNode zero(0);
    TreeNode three(3);
    TreeNode two(2, nullptr, &three);
    TreeNode one(1, &zero, &two);

    TreeNode five(5);
    TreeNode eight(8);
    TreeNode seven(7, nullptr, &eight);
    TreeNode six(6, &five, &seven);

    TreeNode four(4, &one, &six);
    solution.printBST(solution.bstToGst(&four));
    return 0;
}