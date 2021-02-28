#include<iostream>

using namespace std;


// Complete the reverse function below.

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode() : data(0), next(nullptr) {}
    SinglyLinkedListNode(int x) : data(x), next(nullptr) {}
    SinglyLinkedListNode(int x, SinglyLinkedListNode* next) : data(x), next(next) {}
};

SinglyLinkedListNode* dfs(SinglyLinkedListNode* curr, SinglyLinkedListNode* prev) {
    if (!curr)
        return prev;
    SinglyLinkedListNode* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    return dfs(curr, prev);
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    return dfs(head, nullptr);
}

void display(SinglyLinkedListNode* list) {
    struct SinglyLinkedListNode* ptr = list;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    SinglyLinkedListNode six(6);
    SinglyLinkedListNode five(5, &six);
    SinglyLinkedListNode four(4, &five);
    SinglyLinkedListNode three(3, &four);
    SinglyLinkedListNode two(2, &three);
    SinglyLinkedListNode one(1, &two);

    display(reverse(&one));
}