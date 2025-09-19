// delete first node on linked list

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

Node *CreateLinkedList(int arr[], int index, int size) {
    if(index == size) {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp -> next = CreateLinkedList(arr, index+1, size);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    Head = CreateLinkedList(arr, 0, 5);

    if(Head!=NULL) {
        Node *temp = Head;
        Head = Head -> next;
        delete temp;
    }

    while(Head) {
        cout << Head -> data << " ";
        Head = Head -> next;
    }
}

// output:
// 4 6 8 10
// ............................................................................................
// delete last node on linked list

#include <bits/stdc++.h>
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

Node *CreateLinkedList(int arr[], int index, int size) {
    if (index == size) {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    Head = CreateLinkedList(arr, 0, 5);

    if (Head != NULL) {
        if (Head -> next == NULL) {  // only one node is present
            Node *temp = Head;
            delete temp;
            Head = NULL;
        } else {  // more than one node is present
            Node *curr = Head;
            Node *prev = NULL;

            // curr -> next is not NULL

            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            delete curr;
        }
    }

    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}

// output:
// 2 4 6 8
// ............................................................................................
// delete particular node on linked list

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head, *Tail;
    Head = Tail = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    int x = 3;

    for(int i=0; i<5; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
            Tail = Head;
        } else {
            Tail -> next = new Node(arr[i]);
            Tail = Tail -> next;
        }
    }

    if(x==1) {
        Node *temp = Head;
        Head = Head -> next;
        delete temp;
    } else {
        x--;
        Node *curr = Head;
        Node *prev = NULL;

        while(x--) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        delete curr;
    }

    // print final list
    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// output:
// 2 4 8 10
// ............................................................................................
// delete particular node on linked list using recursion

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

Node *deleteNode(Node *curr, int x) {
    if(x==1) {
        Node *temp;
        temp = curr -> next;
        delete curr;
        return temp;
    }

    curr -> next = deleteNode(curr -> next, x-1);
    return curr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head, *Tail;
    Tail = Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    int x = 3;

    for(int i=0; i<5; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
            Tail = Head;
        } else {
            Tail -> next = new Node(arr[i]);
            Tail = Tail -> next;
        }
    }

    Head = deleteNode(Head, x);

    Node *temp;
    temp = Head;

    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 8 10
// ............................................................................................
// delete without head pionter

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

// delete given node without head
void deleteNode(Node *curr) {
    Node *temp = curr->next;
    curr->data = temp->data;
    curr->next = temp->next;
    delete temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Node *Head, *Tail;
    Head = Tail = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    int n = 5;
    int x = 3;

    // create linked list
    for(int i=0; i<n; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
            Tail = Head;
        } else {
            Tail->next = new Node(arr[i]);
            Tail = Tail->next;
        }
    }

    // Suppose we want to delete 3rd node (value 6) without head
    Node *temp = Head;
    for(int i=1; i<x; i++) {  
        temp = temp->next;
    }  

    deleteNode(temp);

    // print updated list
    temp = Head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// output:
// 2 4 8 10