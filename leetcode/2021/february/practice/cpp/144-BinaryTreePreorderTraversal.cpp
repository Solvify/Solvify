#include<iostream>
#include<vector>
#include<stack>


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
    //recursive approch
    void preorder(TreeNode* root, vector<int>& res) {
        if (!root)   return;
        res.push_back(root->val);
        if (root->left)  preorder(root->left, res);
        if (root->right)  preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    // itrative approch
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)   return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* top = st.top();
            ans.push_back(top->val);
            st.pop();
            if (top->right) st.push(top->right);
            if (top->left)   st.push(top->left);
        }
        return ans;
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


    for (int num : solution.preorderTraversal(&four)) {
        cout << num << " ";
    }


    return 0;
}