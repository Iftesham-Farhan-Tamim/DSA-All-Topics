// Clone a linked list with next and random pointer (https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *arb;

    Node(int value) {
        data = value;
        next = NULL;
        arb = NULL;
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

void printLinkedList(Node* head) {
	Node* curr = head;

	while (curr) {
		cout << curr -> data << "(";

		if (curr -> arb) {
			cout << curr -> arb -> data;
		} else {
			cout << "NULL";
		}

		cout << ") -> ";
		curr = curr -> next;
	}

	cout << "NULL";
}

Node *find(Node *curr1, Node *curr2, Node *x) {
    if(x == NULL) {
        return NULL;
    }

    while(curr1 != x) {
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }

    return curr2;
}

Node *copyList(Node *Head) {
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = Head;

    while(temp) {
        tailCopy -> next = new Node(temp -> data);
        tailCopy = tailCopy -> next;
        temp = temp -> next;
    }

    tailCopy = headCopy;
    headCopy = headCopy -> next;
    delete tailCopy;

    tailCopy = headCopy;
    temp = Head;

    while(temp) {
        tailCopy -> arb = find(Head, headCopy, temp -> arb);
        tailCopy = tailCopy -> next;
        temp = temp -> next;
    }

    return headCopy;
}

int main() {
    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5);

    Head->arb = Head->next->next;          
    Head->next->arb = Head;                
    Head->next->next->arb = Head->next->next->next->next;  
    Head->next->next->next->arb = Head->next->next;        
    Head->next->next->next->next->arb = Head->next;           

    cout << "Original list: ";
    printLinkedList(Head);

    Node *Copied = copyList(Head);
    cout << endl;

    cout << "Copied list:   ";
    printLinkedList(Copied);
}

// output:
// Original list: 2(6) -> 4(2) -> 6(10) -> 8(6) -> 10(4) -> NULL
// Copied list:   2(6) -> 4(2) -> 6(10) -> 8(6) -> 10(4) -> NULL
// // ............................................................................................
// Optimized sloution - clone a linked list

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *arb;

    Node(int value) {
        data = value;
        next = NULL;
        arb = NULL;
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

void printLinkedList(Node* head) {
	Node* curr = head;

	while (curr) {
		cout << curr -> data << "(";

		if (curr -> arb) {
			cout << curr -> arb -> data;
		} else {
			cout << "NULL";
		}

		cout << ") -> ";
		curr = curr -> next;
	}

	cout << "NULL";
}

Node *copyList(Node *Head) {
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = Head;

    while(temp) {
        tailCopy -> next = new Node(temp -> data);
        tailCopy = tailCopy -> next;
        temp = temp -> next;
    }

    tailCopy = headCopy;
    headCopy = headCopy -> next;
    delete tailCopy;

    tailCopy = headCopy;
    temp = Head;

    unordered_map<Node*, Node*> m;

    while(temp) {
        m[temp] = tailCopy;
        tailCopy = tailCopy -> next;
        temp = temp -> next;
    }

    tailCopy = headCopy;
    temp = Head;

    while(temp) {
        tailCopy -> arb = m[temp -> arb];
        tailCopy = tailCopy -> next;
        temp = temp -> next;
    }

    return headCopy;
}

int main() {
    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5);

    Head->arb = Head->next->next;          
    Head->next->arb = Head;                
    Head->next->next->arb = Head->next->next->next->next;  
    Head->next->next->next->arb = Head->next->next;        
    Head->next->next->next->next->arb = Head->next;           

    cout << "Original list: ";
    printLinkedList(Head);

    Node *Copied = copyList(Head);
    cout << endl;

    cout << "Copied list:   ";
    printLinkedList(Copied);
}

// output:
// Original list: 2(6) -> 4(2) -> 6(10) -> 8(6) -> 10(4) -> NULL
// Copied list:   2(6) -> 4(2) -> 6(10) -> 8(6) -> 10(4) -> NULL
// // ............................................................................................
// Most optimized approach-clone a linked list

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *arb;

    Node(int value) {
        data = value;
        next = NULL;
        arb = NULL;
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

void printLinkedList(Node* head) {
	Node* curr = head;

	while (curr) {
		cout << curr -> data << "(";

		if (curr -> arb) {
			cout << curr -> arb -> data;
		} else {
			cout << "NULL";
		}

		cout << ") -> ";
		curr = curr -> next;
	}

	cout << "NULL";
}

Node *copyList(Node *Head) {
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = Head;

    while(temp) {
        tailCopy -> next = new Node(temp -> data);
        tailCopy = tailCopy -> next;
        temp = temp -> next;
    }

    tailCopy = headCopy;
    headCopy = headCopy -> next;
    delete tailCopy;

    tailCopy = headCopy;
    temp = Head;

    Node *curr1 = Head, *curr2 = headCopy;
    Node *front1, *front2;

    while(curr1) {
        front1 = curr1 -> next;
        front2 = curr2 -> next;
        curr1 -> next = curr2;
        curr2 -> next = front1;
        curr1 = front1;
        curr2 = front2;
    }

    curr1 = Head;

    while(curr1) {
        curr2 = curr1 -> next;
        if(curr1 -> arb) {
            curr2 -> arb = curr1 -> arb -> next;
        }
        curr1 = curr2 -> next;
    }

    curr1 = Head;
    while(curr1 -> next) {
        front1 = curr1 -> next;
        curr1 -> next = front1 -> next;
        curr1 = front1;
    }

    return headCopy;
}

int main() {
    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5);

    Head->arb = Head->next->next;          
    Head->next->arb = Head;                
    Head->next->next->arb = Head->next->next->next->next;  
    Head->next->next->next->arb = Head->next->next;        
    Head->next->next->next->next->arb = Head->next;         

    cout << "Original list: ";
    printLinkedList(Head);

    Node *Copied = copyList(Head);
    cout << endl;

    cout << "Copied list:   ";
    printLinkedList(Copied);
}

// output:
// Original list: 2(6) -> 4(2) -> 6(NULL) -> 8(NULL) -> 10(NULL) -> NULL
// Copied list:   2(6) -> 4(2) -> 6(NULL) -> 8(NULL) -> 10(NULL) -> NULL