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
    Head = new Node(4);

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
        if(Head == NULL) {  // linked list doesn't exist
            Head = new Node(arr[i]);
        }else {  // linked list exists
            Node *temp;
            temp = new Node(arr[i]);
            temp -> next = Head;
            Head = temp;
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
        }else {  // linked list exists
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