#include<iostream>

using namespace std;

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
    TreeNode* dfs(TreeNode* root, int depth) {
        if (root->left)
            dfs(root->left, depth);
        if (root->right)
            dfs(root->right, depth);
        return root;

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return root;
    }
};

void displayInOrder(TreeNode* root) {
    if (root->left != nullptr)
        displayInOrder(root->left);
    cout << root->val << " ";
    if (root->right != nullptr)
        displayInOrder(root->right);
}

int main() {
    TreeNode seven(7);
    TreeNode four(4);
    TreeNode two(2, &seven, &four);
    TreeNode six(6);
    TreeNode five(5, &six, &two);
    TreeNode zero(0);
    TreeNode eight(8);
    TreeNode one(1, &zero, &eight);
    TreeNode three(3, &five, &one);

    Solution solution;
    displayInOrder(solution.lcaDeepestLeaves(&three));
    return 0;
}