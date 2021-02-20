#include<iostream>
#include<algorithm>

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
    int maxDepth(TreeNode* root, int depth) {
        if (root == nullptr)   return depth;
        depth++;
        return max(maxDepth(root->left, depth), maxDepth(root->right, depth));
    }
    int maxDepth(TreeNode* root) {
        if (!root)   return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    TreeNode l1(2);
    TreeNode n1(1, &l1, nullptr);
    Solution solution;
    cout << "\n " << solution.maxDepth(&n1) << endl;
    return 0;
}