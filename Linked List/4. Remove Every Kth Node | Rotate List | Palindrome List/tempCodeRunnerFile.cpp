#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node *createLinkedList(int arr[], int idx, int size, Node *back) {
    if (idx == size) {
        return NULL;
    }

    Node *temp = new Node(arr[idx]);
    temp->prev = back;
    temp->next = createLinkedList(arr, idx + 1, size, temp);

    return temp;
}

Node* reverseDLL(Node* head) {
    if (!head || !head->next) return head; // empty or single node

    Node* curr = head;
    Node* temp = NULL;

    while (curr) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to "next" (which is actually prev after swap)
        curr = curr->prev;
    }

    // After loop, temp points to the node before new head
    if (temp) {
        head = temp->prev;
    }
    return head;
}

int main() {
    Node *Head = NULL;
    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    Head = reverseDLL(Head);

    Node *temp;
    temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}