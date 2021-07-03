#include<iostream>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* dfs(Node* head) {
        if (!head->child) {
            dfs(head->next);
        }

        return head;
    }
    Node* flatten(Node* head) {
        Node* temp = head;
        dfs(temp);
        return head;
    }
};

void display(Node* list) {
    struct Node* ptr = list;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


int main() {
    Solution solution;




    return 0;
}