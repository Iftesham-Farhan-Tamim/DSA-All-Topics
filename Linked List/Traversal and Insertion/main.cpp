// creating linked list

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
    Node *Head;
    Head = new Node(4);  // new is a dynamic memory allocation operator.

    cout << Head -> data << endl;
    cout << Head -> next << endl;
}

// output:
// 4
// 0x0
// ............................................................................................
// insertion on linkedlist at start

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
    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    
    for(int i=0; i<5; i++) {
        if(Head == NULL) {  
            Head = new Node(arr[i]);
        } else {  
            Node *temp;
            temp = new Node(arr[i]);
            temp -> next = Head;  // link new node to the existing list
            Head = temp;  // update Head to point to the new node
        }
    }

    // print the value

    Node *temp = Head;

    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 10 8 6 4 2
// ............................................................................................
// insertion at ending

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
    Node *Head, *Tail;
    Tail = Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    for(int i=0; i<5; i++) {
        if(Head == NULL) {  // linked list is empty
            Head = new Node(arr[i]);
            Tail = Head;
        } else {  // linked list exists
            Tail -> next = new Node(arr[i]);
            Tail = Tail -> next;
        }
    }

    Node *temp;
    temp = Head;

    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 6 8 10 
// ............................................................................................
// creating linked list using recursion adding note at end

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
    // base case
    if(index==size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp -> next = CreateLinkedList(arr, index+1, size);

    return temp;  // head of the current sublist
}

int main() {
    Node *Head, *Tail;
    Tail = Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = CreateLinkedList(arr, 0, 5);

    Node *temp;
    temp = Head;

    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 6 8 10 
// ............................................................................................
// inserting node at begining using recursion

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node *CreateLinkedList(int arr[], int index, int size, Node *prev) {
    // base case
    if(index == size) {
        return prev;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp -> next = prev;
    return CreateLinkedList(arr, index+1, size, temp);
}

int main() {
    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    Head = CreateLinkedList(arr, 0, 5, NULL);

    Node *temp;
    temp = Head;

    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 10 8 6 4 2
// ............................................................................................
// inserting node at particular position

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
    // base case
    if(index == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp -> next = CreateLinkedList(arr, index+1, size);

    return temp;    
}

int main() {
    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    Head = CreateLinkedList(arr, 0, 5);

    int x = 3;
    int value = 30;

    Node *temp;
    temp = Head;
    x--;

    while(x--) {
        temp = temp -> next;
    }

    Node *temp2 = new Node(value);
    temp2 -> next = temp -> next;
    temp -> next = temp2;

    temp = Head;

    while(temp!=NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 6 30 8 10