// Flattening a linked list

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node *bottom;

	Node(int value) {
		data = value;
		next = NULL;
		bottom = NULL;
	}
};

Node *createLinkedList(int arr[], int idx, int size) {
	if (idx == size) {
		return NULL;
	}

	Node *temp = new Node(arr[idx]);
	temp -> bottom = createLinkedList(arr, idx + 1, size);
	return temp;
}

void printLinkedList(Node* Head) {
	Node* temp = Head;

	while (temp) {
		cout << temp -> data;
		if (temp -> bottom) {
			cout << " -> ";
		}
		temp = temp -> bottom;
	}
}

Node *mergesort(Node *Head1, Node *Head2) {
	Node *curr1 = Head1, *curr2 = Head2;
	Node *tail = new Node(0);
	Node *tailCopy = tail;

	while (curr1 && curr2) {
		if (curr1 -> data <= curr2 -> data) {
			tail -> bottom = curr1;
			curr1 = curr1 -> bottom;
			tail = tail -> bottom;
		} else {
			tail -> bottom = curr2;
			curr2 = curr2 -> bottom;
			tail = tail -> bottom;
		}
	}

	if (curr1) {
		tail -> bottom = curr1;
	} else {
		tail -> bottom = curr2;
	}

	return tailCopy -> bottom;
}

Node *flatten(Node *root) {
	Node *Head1, *Head2, *Head3;

	while (root -> next) {
		Head1 = root;
		Head2 = root -> next;
		Head3 = root -> next -> next;

		Head1 -> next = NULL;
		Head2 -> next = NULL;

		root = mergesort(Head1, Head2);
		root -> next = Head3;
	}

	return root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Node* Head = new Node(5);
	Head -> bottom = new Node(7);
	Head -> bottom -> bottom = new Node(8);
	Head -> bottom -> bottom -> bottom = new Node(30);

	Head -> next = new Node(10);
	Head -> next -> bottom = new Node(20);
	Head -> next -> bottom -> bottom = new Node(40);

	Head -> next -> next = new Node(19);
	Head -> next -> next -> bottom = new Node(22);
	Head -> next -> next -> bottom -> bottom = new Node(50);

	Head -> next -> next -> next = new Node(28);
	Head -> next -> next -> next -> bottom = new Node(35);
	Head -> next -> next -> next -> bottom -> bottom = new Node(40);
	Head -> next -> next -> next -> bottom -> bottom -> bottom = new Node(45);

	Head -> next -> next -> next -> next = new Node(30);
	Head -> next -> next -> next -> next -> bottom = new Node(34);
	Head -> next -> next -> next -> next -> bottom -> bottom = new Node(40);

	Head = flatten(Head);

	printLinkedList(Head);
}

// output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 30 -> 34 -> 35 -> 40 -> 40 -> 40 -> 45 -> 50
// ............................................................................................
// Merge k sorted linked list

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

void printLinkedList(Node* Head) {
    Node* temp = Head;

    while (temp) {
        cout << temp -> data;
        if(temp -> next) {
            cout << " -> ";
        }
        temp = temp -> next;
    }
}

Node *merge(Node *Head1, Node *Head2) {
    Node *Head = new Node(0);
    Node *tail = Head;

    while(Head1 && Head2) {
        if(Head1 -> data <= Head2 -> data) {
            tail -> next = Head1;
            Head1 = Head1 -> next;
            tail = tail -> next;
            tail -> next = NULL;
        } else {
            tail -> next = Head2;
            Head2 = Head2 -> next;
            tail = tail -> next;
            tail -> next = NULL;
        }
    }

    if(Head1) {
        tail -> next = Head1;
    } else {
        tail -> next = Head2;
    }

    return Head -> next;
}

Node *mergeKLists(Node *arr[], int k) {
    Node *Head = arr[0];

    for(int i=1; i<k; i++) {
        Head = merge(Head, arr[i]);
    }

    return Head;
}

int main() {
    Node *arr[3];

    int a1[] = {2, 4, 6};
    int a2[] = {1, 3, 5};
    int a3[] = {7, 8, 9};

    arr[0] = createLinkedList(a1, 0, 3);
    arr[1] = createLinkedList(a2, 0, 3);
    arr[2] = createLinkedList(a3, 0, 3);

    Node *Head = mergeKLists(arr, 3);

    printLinkedList(Head);  
}

// output:
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
// // ............................................................................................
// Merge K sorted linked list using merge sort

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

void printLinkedList(Node* Head) {
    Node* temp = Head;

    while (temp) {
        cout << temp -> data;
        if(temp -> next) {
            cout << " -> ";
        }
        temp = temp -> next;
    }
}

Node *merge(Node *Head1, Node *Head2) {
    Node *Head = new Node(0);
    Node *tail = Head;

    while(Head1 && Head2) {
        if(Head1 -> data <= Head2 -> data) {
            tail -> next = Head1;
            Head1 = Head1 -> next;
            tail = tail -> next;
        } else {
            tail -> next = Head2;
            Head2 = Head2 -> next;
            tail = tail -> next;
        }
    }

    if(Head1) {
        tail -> next = Head1;
    } else {
        tail -> next = Head2;
    }

    return Head -> next;
}

void mergesort(Node *arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int mid = start + (end-start)/2;

    mergesort(arr, start, mid);

    mergesort(arr, mid+1, end);

    arr[start] = merge(arr[start], arr[mid+1]);
}

Node *mergeKLists(Node *arr[], int k) {
    Node *Head = arr[0];

    for(int i=1; i<k; i++) {
        Head = merge(Head, arr[i]);
    }

    return Head;
}

int main() {
    Node *arr[3];

    int a1[] = {2, 4, 6};
    int a2[] = {1, 3, 5};
    int a3[] = {7, 8, 9};

    arr[0] = createLinkedList(a1, 0, 3);
    arr[1] = createLinkedList(a2, 0, 3);
    arr[2] = createLinkedList(a3, 0, 3);

    Node *Head = mergeKLists(arr, 3);

    printLinkedList(Head);  
}

// output:
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9