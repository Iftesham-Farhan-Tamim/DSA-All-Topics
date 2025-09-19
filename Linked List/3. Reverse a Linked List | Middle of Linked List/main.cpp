// Vector method: Changes the data values only. Memory O(n).
// Pointer method: Changes the node connections. Memory O(1).


// Reverse Node of a LinkedList [Vector-based reversal]

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

Node *CreateLinkedList(int arr[], int idx, int size) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> next = CreateLinkedList(arr, idx+1, size);

    return temp;
}

Node *ReverseLinkedList(Node *Head) {
    vector<int> values;
    Node *temp = Head;

    while(temp != NULL) {
        values.push_back(temp -> data);
        temp = temp -> next;
    }

    int i = values.size() - 1;
    temp = Head;
    while(temp!=NULL) {
        temp -> data = values[i];
        i--;
        temp = temp -> next;
    }

    return Head;
}

void PrintLinkedList(Node *Head) {
    Node *temp;
    temp = Head;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    Head = CreateLinkedList(arr, 0, 5);
    cout << "Original List: ";
    PrintLinkedList(Head);

    ReverseLinkedList(Head);
    cout << "Reverse List: ";
    PrintLinkedList(Head);
}

// output:
// Original List: 2 4 6 8 10 
// Reverse List: 10 8 6 4 2 
// ............................................................................................
// Reverse Node of a LinkedList [Pointer-based reversal (real linked list reversal)]

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

Node *CreateLinkedList(int arr[], int idx, int size) {
	if (idx == size) {
		return NULL;
	}

	Node *temp;
	temp = new Node(arr[idx]);
	temp -> next = CreateLinkedList(arr, idx + 1, size);

	return temp;
}

Node *ReverseList(Node *Head) {
	Node *prev = NULL;
	Node *curr = Head;
    Node *fut = NULL;

	while (curr != NULL) {
		fut = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fut;
	}

    Head = prev;
	return Head;
}

void printList(Node *Head) {
	Node *temp;
	temp = Head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	Node *Head;
	Head = NULL;

	int arr[] = {2, 4, 6, 8, 10};

	Head = CreateLinkedList(arr, 0, 5);
	cout << "Orignal List: ";
	printList(Head);

	cout << endl;
	
    Head = ReverseList(Head);
	cout << "Reverse List : ";
	printList(Head);
}

// output:
// Orignal List: 2 4 6 8 10 
// Reverse List : 10 8 6 4 2
// ............................................................................................
// Reverse nodes of LinkedList using recursion

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = NULL;
    }
};

Node *CreateLinkedList(int arr[], int idx, int size) {
    if (idx == size) {
        return NULL;
    }

    Node* temp = new Node(arr[idx]);
    temp->next = CreateLinkedList(arr, idx + 1, size);
    return temp;
}

// Recursive reverse function
Node *ReverseList(Node* curr, Node *prev) {
    if (curr == NULL) {  // new head
        return prev; 
    }
    
    Node* fut = curr->next;
    curr->next = prev;
    return ReverseList(fut, curr);
}

// Public helper to call recursive reverse
Node *ReverseList(Node *Head) {
    return ReverseList(Head, NULL);
}

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {2, 4, 6, 8, 10};
    Node* Head = CreateLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printList(Head);

    Head = ReverseList(Head); // recursive reversal

    cout << "\nReversed List: ";
    printList(Head);
}

// output:
// Original List: 2 4 6 8 10 
// Reversed List: 10 8 6 4 2
// ............................................................................................
// Middle of LinkedList(two-pass approach)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* CreateLinkedList(int arr[], int idx, int size) {
    if (idx == size) {
        return NULL;
    }

    Node* temp;
    temp = new Node(arr[idx]);
    temp->next = CreateLinkedList(arr, idx + 1, size);

    return temp;
}

Node* middleNode(Node* Head) {
    int count = 0;
    Node* temp = Head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    count /= 2;
    temp = Head;
    while (count--) {
        temp = temp->next;
    }

    return temp;
}

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {2, 4, 6, 8, 10};
    Node* Head = CreateLinkedList(arr, 0, 5);

    Node* middle = middleNode(Head);
    cout << "Middle Node: " << middle->data << endl;
}

// output:
// Middle Node: 6
// ............................................................................................
// Middle of LinkedList(Slow and Fast Pointer Method also known as Tortoise and Hare Algorithm)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* CreateLinkedList(int arr[], int idx, int size) {
    if (idx == size) {
        return NULL;
    }

    Node* temp;
    temp = new Node(arr[idx]);
    temp->next = CreateLinkedList(arr, idx + 1, size);

    return temp;
}

// Slow–Fast pointer method to find middle node
Node* middleNode(Node* Head) {
    Node* slow = Head;
    Node* fast = Head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {2, 4, 6, 8, 10};
    Node* Head = CreateLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printList(Head);

    Node* middle = middleNode(Head);
    cout << "\nMiddle Node: " << middle->data << endl;
}

// output:
// Original List: 2 4 6 8 10 
// Middle Node: 6