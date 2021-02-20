#include<iostream>
#include<queue>



using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BSTIterator {
public:
    queue<int> q;
    void inorderTriversAndPutIntoQueue(TreeNode* temp){
        if(temp->left)
            inorderTriversAndPutIntoQueue(temp->left);
        q.push(temp->val);
        if(temp->right)
            inorderTriversAndPutIntoQueue(temp->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorderTriversAndPutIntoQueue(root);
    }
    
    int next() {
        int next = q.front();
        q.pop();
        return next;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


int main() {

    TreeNode t(20);
    TreeNode n(9);
    TreeNode th(3);
    TreeNode f(15,&n,&t);
    TreeNode root(7,&th,&f);

    BSTIterator* obj = new BSTIterator(&root);
    
   while (obj->hasNext())   {
      cout << obj->next() << " ";
   }
   
    return 0;
}