#include <iostream>
#include <vector>

using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    static TreeNode *insert(TreeNode *root, int value) {
        if(!root){
            return new TreeNode(value);
        }
        if(value > root->val) {
            root->right = insert(root->right, value);
        } else {
            root->left = insert(root->left, value);
        }
        return root;
    }

    void inorder(TreeNode *root) {
        if(!root)   return;
        inorder(root->left);
        cout << root->val<<" ";
        inorder(root->right);
    }

    TreeNode* bstFromPreorder(vector<int> preorder) {
        TreeNode *root = nullptr;
        root  = insert(root,preorder.at(0));
        for(int i=1; i<preorder.size(); i++) {
            insert(root,preorder.at(i));
        }
        return root;
    }
};
int main() {
    vector<int> v{8,5,1,7,10,12};
    Solution solution;
    solution.bstFromPreorder(v);
    return 0;
}