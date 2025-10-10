// Add 2 numbers represented by linked list (https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node *createLinkedList(int arr[], int idx, int size) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> next = createLinkedList(arr, idx+1, size);
    return temp;
}

void printLinkedList(Node *Head) {
    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node *reverse(Node *Head) {
    Node *prev = NULL;
    Node *curr = Head;
    Node *fut = NULL;

    while (curr) {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }

    return prev;
}

Node *addTwoLists(Node *first, Node *second) {
    first = reverse(first);
    second = reverse(second);

    Node *curr1 = first, *curr2 = second;
    Node *head = new Node(0);
    Node *tail = head;

    int sum, carry = 0;

    while(curr1 && curr2) {
        sum = curr1 -> data + curr2 -> data + carry;
        tail -> next = new Node(sum % 10);
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
        tail = tail -> next;
        carry = sum / 10;
    }

    while(curr1) {
        sum = curr1 -> data + carry;
        tail -> next = new Node(sum % 10);
        curr1 = curr1 -> next;
        tail = tail -> next;
        carry = sum / 10;
    }

    while(curr2) {
        sum = curr2 -> data+carry;
        tail -> next = new Node(sum % 10);
        curr2 = curr2 -> next;
        tail = tail -> next;
        carry = sum / 10;
    }

    while(carry) {
        tail -> next = new Node(carry % 10);
        tail = tail -> next;
        carry /= 10;
    }

    head = reverse(head -> next);
    return head;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int arr1[] = {2, 4, 6, 8, 10};
    Node *first = createLinkedList(arr1, 0, 5);

    int arr2[] = {1, 3, 5, 7};
    Node *second = createLinkedList(arr2, 0, 4);

    cout << "First List: ";
    printLinkedList(first);
    cout << "\nSecond List: ";
    printLinkedList(second);

    Node *sumList = addTwoLists(first, second);
    cout << "\nSum List: ";
    printLinkedList(sumList);
    cout << endl;
}

// output:
// First List: 2 4 6 8 10 
// Second List: 1 3 5 7 
// Sum List: 2 6 0 4 7 
// ............................................................................................
// Reverse a linked list in group of sizes (https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node *createLinkedList(int arr[], int idx, int size) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> next = createLinkedList(arr, idx+1, size);
    return temp;
}

void printLinkedList(Node *Head) {
    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node *reverseIt(Node *Head, int k) {
    Node *first = new Node(0);
    first -> next = Head;
    Head = first;
    int x;
    Node *second, *prev, *curr, *front;

    while(first -> next) {
        int x = k;
        second = first -> next;
        prev = first;
        curr = first -> next;

        while(x && curr) {
            front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
            x--;
        }

        first -> next = prev;
        second -> next = curr;
        first = second;
    }

    first = Head;
    Head = Head -> next;
    delete first;

    return Head;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    Node* head = createLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printLinkedList(head);
    cout << endl;

    int k = 2;
    head = reverseIt(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printLinkedList(head);
    cout << endl;
}

// output:
// Original List: 2 4 6 8 10 
// Reversed in groups of 2: 4 2 8 6 10