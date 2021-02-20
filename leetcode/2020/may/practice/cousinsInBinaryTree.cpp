#include <iostream>
#include <map>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

map<int,int> parents;
int getLevelAndParent(struct TreeNode *node, int data, int level, struct TreeNode *parent) {
    if (node == nullptr)
        return 0;

    if (node -> data == data) {
        if(parent!= nullptr)    parents[node->data] = parent->data;
        return level;
    }
    int downlevel = getLevelAndParent(node->left, data, level + 1, node);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelAndParent(node->right, data, level + 1, node);
    return downlevel;
}
bool isCousins(struct TreeNode *root, int x, int y) {
    return ((getLevelAndParent(root, x, 1, nullptr) == getLevelAndParent(root, y, 1, nullptr)) && (parents[x] != parents[y]));
}

struct TreeNode* newNode(int data)  {
    auto *temp = new struct TreeNode;
    temp -> data = data;
    temp -> left = nullptr;
    temp -> right = nullptr;

    return temp;
}

// Driver Code
int main()
{
    auto *root = new struct TreeNode;

    /* Constructing tree given in
    the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->left = newNode(8);
    root->right->right = newNode(7);
    cout <<"Enter the value of x & y : ";
    int x,y;
    cin>>x>>y;

    if(isCousins(root,x,y))
        cout<<"They are cosines re baba.";
    else
        cout<<"They are not cosines.";
    return 0;
}