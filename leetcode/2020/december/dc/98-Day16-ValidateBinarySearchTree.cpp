#include<iostream>
#include<vector>

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
    bool inOrder(TreeNode* root,vector<int>& sorted_array) {
        if(root->left) 
            inOrder(root->left,sorted_array);
        sorted_array.push_back(root->val);
        if(root->right)
            inOrder(root->right,sorted_array);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> sorted_array;
        inOrder(root,sorted_array);
        int max = sorted_array[0];
        for(int i=1; i<sorted_array.size(); i++) 
            if(sorted_array[i] > max)  max = sorted_array[i];
            else return false;
        return true;
    }
};

int main() {

    TreeNode three(3);
    TreeNode six(6);
    TreeNode four(4,&three,&six);
    TreeNode one(1);
    TreeNode oneMore(1,&one,nullptr);

    Solution solution;
    cout << solution.isValidBST(&oneMore)<<endl;
    return 0;
}