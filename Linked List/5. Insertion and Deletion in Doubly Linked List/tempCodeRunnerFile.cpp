#include<bits/stdc++.h>
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

Node *createLinkedlist(int arr[], int idx, int size, Node *back) {
	if (idx == size) {
		return NULL;
	}

	Node *temp = new Node(arr[idx]);
	temp -> prev = back;
	temp -> next = createLinkedlist(arr, idx + 1, size, temp);
	return temp;
}

void printLinkedList(Node *Head) {
	Node *temp;
	temp = Head;

	while (temp) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

Node *insertStart(Node *Head) {
	Node *temp;
	temp = new Node(5);

	if (Head == NULL) {
		Head = temp;
	} else {
		Head -> prev = temp;
		temp -> next = Head;
		Head = temp;
	}

	return Head;
}

Node *insertEnd(Node *Head) {
	Node *temp;
	temp = new Node(5);

	if (Head == NULL) {
		Head = temp;
	} else {
		Node *curr;
		curr = Head;

		while (curr -> next) {
			curr = curr -> next;
		}

		curr -> next = temp;
		temp -> prev = curr;
	}

	return Head;
}

Node *insertAtAnyPoint(Node *Head, int pos) {
	Node *temp;
	temp = new Node(5);

	if (pos == 0) {
		if (Head == NULL) {
			Head = temp;
		} else {
			Head -> prev = temp;
			temp -> next = Head;
			Head = temp;
		}
	} else {
		Node *curr = Head;

		while (--pos) {
			curr = curr -> next;
		}

		// at end
		if (curr -> next == NULL) {
			temp -> prev = curr;
			curr -> next = temp;
		} else {  // at any point
			temp -> prev = curr;
			temp -> next = curr -> next;
			curr -> next -> prev = temp;
			curr -> next = temp;
		}
	}

	return Head;
}

Node *deleteStart(Node *Head) {
	if (Head == NULL) {
		return NULL;
	}

	Node *temp = Head;
	Head = Head -> next;

	if (Head != NULL) {
		Head -> prev = NULL;
	}

	delete temp;
	return Head;
}

Node *deleteEnd(Node *Head) {
	if (Head == NULL) {
		return NULL;
	}

	Node *temp = Head;

	if (Head -> next == NULL) {
		delete Head;
		return NULL;
	}

	while (temp -> next) {
		temp = temp -> next;
	}

	temp -> prev -> next = NULL;
	delete temp;

	return Head;
}

Node *deleteAtAnyPoint(Node *Head, int pos) {
	if (Head == NULL) return NULL;

	// Delete first node (pos = 1)
	if (pos == 1) {
		Node *temp = Head;
		Head = Head->next;

		if (Head != NULL) {
			Head->prev = NULL;
		}

		delete temp;
		return Head;
	}

	// Traverse to the node at position pos
	Node *temp = Head;
	while (--pos) {
		temp = temp -> next;
	}

	if (temp == NULL) {  // pos out of range
		return Head;
	}

	// Delete last node
	if (temp->next == NULL) {
		temp->prev->next = NULL;
		delete temp;
	} else { // Delete middle node
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}

	return Head;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Node *Head;
	Head = NULL;

	int arr[] = {2, 4, 6, 8, 10};
	Head = createLinkedlist(arr, 0, 5, NULL);

	// Head = insertStart(Head);
	// Head = insertEnd(Head);
	Head = insertAtAnyPoint(Head, 2);
	// Head = deleteStart(Head);
	// Head = deleteEnd(Head);
	// Head = deleteAtAnyPoint(Head, 2);

	printLinkedList(Head);
}