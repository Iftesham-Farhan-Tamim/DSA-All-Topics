// inserting node on doubly linked list (https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head = NULL;

    if(Head==NULL) {
        Head = new Node(5);
    } else {
        Node *temp = new Node(5);
        temp -> next = Head;
        Head -> prev = temp;
        Head = temp;
    }

    Node *trav = Head;
    while(trav) {
        cout << trav -> data << " ";
        trav = trav -> next;
    }
}

// output:
// 5
// ............................................................................................
// converting array into doubly linked list

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node (int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head = NULL;
    Node *Tail = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    for(int i=0; i<5; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
            Tail = Head;
        } else {
            Node *temp = new Node(arr[i]);
            Tail -> next = temp;
            temp -> prev = Tail;
            Tail = temp;
        }
    }

    Node *temp;
    temp = Head;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 6 8 10
// ............................................................................................
// converting array into doubly linked list (recursive approach)

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

Node *createLinkedList(int arr[], int idx, int size, Node *back) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> prev = back;
    temp -> next = createLinkedList(arr, idx+1, size, temp);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    Node *temp;
    temp = Head;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 6 8 10
// ............................................................................................
// insertion at any point on doubly linked list

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node (int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head;
    Head = NULL;

    Node *Tail;
    Tail = NULL;

    int arr[] = {2, 4, 6, 8, 10};

    for(int i=0; i<5; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
            Tail = Head;
        } else {
            Node *temp = new Node(arr[i]);
            Tail -> next = temp;
            temp -> prev = Tail;
            Tail = temp;
        }
    }

    int pos = 2;

    if(pos == 0) {
        if(Head == NULL) {
            Head = new Node(5);
        } else {
            Node *temp;
            temp = new Node(5);
            temp -> next = Head;
            Head -> prev = temp;
            Head = temp;
        }
    } else {
        Node *curr = Head;
        // go to the node, after which I have to insert
        while(--pos) {
            curr = curr -> next;
        }

        //  insert at end
        if(curr -> next == NULL) {
            Node *temp = new Node(5);
            temp -> prev = curr;
            curr -> next = temp;
        } else {  // insert at any point
            Node *temp = new Node(5);
            temp -> next = curr -> next;
            temp -> prev = curr;
            curr -> next = temp;
            temp -> next -> prev = temp;
        }
    }

    Node *temp;
    temp = Head;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 5 6 8 10
// ............................................................................................
// insertion node on doubly linked list (at end)

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

Node *createLinkedList(int arr[], int idx, int size, Node *back) {
	if (idx == size) {
		return NULL;
	}

	Node *temp;
	temp = new Node(arr[idx]);
	temp -> prev = back;
	temp -> next = createLinkedList(arr, idx + 1, size, NULL);

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Node *Head;
	Head = NULL;

	int arr[] = {2, 4, 6, 8, 10};
	Head = createLinkedList(arr, 0, 5, NULL);

	if (Head == NULL) {
		Head = new Node(5);
	} else {
		Node *temp = new Node(5);
		Node *Tail = Head;

		while (Tail -> next) {
			Tail = Tail -> next;
		}

		temp -> prev = Tail;
		Tail -> next = temp;
	}

	printLinkedList(Head);
}

// output:
// 2 4 6 8 10 5
// ............................................................................................
// deletion at start and end on doubly linked list

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

Node *createLinkedList(int arr[], int idx, int size, Node *back) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> prev = back;
    temp -> next = createLinkedList(arr, idx+1, size, temp);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    if(Head!=NULL) {
        if(Head -> next == NULL) {
            delete Head;
            Head = NULL;
        } else {
            Node *temp = Head;
            delete temp;
            Head = Head -> next;
            Head -> prev = NULL;
        }
    }

    Node *temp;
    temp = Head;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 4 6 8 10
// ............................................................................................
// deletion at end on doubly linked list

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

Node *createLinkedList(int arr[], int idx, int size, Node *back) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> prev = back;
    temp -> next = createLinkedList(arr, idx+1, size, temp);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    if(Head!=NULL) {
        if(Head -> next == NULL) {
            delete Head;
            Head = NULL;
        } else {
            Node *curr = Head;
            while(curr -> next) {
                curr = curr -> next;
            }

            curr -> prev -> next = NULL;
            delete curr;
        }
    }

    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 6 8
// ............................................................................................
// deletion at any point on linked list

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

Node *createLinkedList(int arr[], int idx, int size, Node *back) {
    if(idx == size) {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[idx]);
    temp -> prev = back;
    temp -> next = createLinkedList(arr, idx+1, size, temp);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Node *Head;
    Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    int pos = 3;

    if (Head == NULL) {
        return NULL;
    }

    if(pos == 1) {
        if(Head -> next == NULL) {
            delete Head;
            Head = NULL;
        } else {
            Node *temp = Head;
            Head = Head -> next;
            delete temp;
            Head -> prev = NULL;
        }
    } else {
        Node *curr = Head;
        while(--pos) {
            curr = curr -> next;
        }

        if (curr == NULL) {
            return Head;   //  position out of range
        }

        if(curr -> next == NULL) {
            curr -> prev -> next = NULL;
            delete curr;
        } else {
            curr -> prev -> next = curr -> next;
            curr -> next -> prev = curr -> prev;
            delete curr;
        }
    }

    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 4 8 10
// ............................................................................................

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
		temp -> next = NULL;
		temp -> prev = NULL;
		Head = temp;
	} else {
		Head -> prev = temp;
		temp -> next = Head;
		temp -> prev = NULL;
		Head = temp;
	}

	return Head;
}

Node *insertEnd(Node *Head) {
	Node *temp;
	temp = new Node(5);

	if (Head == NULL) {
		temp -> next = NULL;
		temp -> prev = NULL;
		Head = temp;
	} else {
		Node *curr;
		curr = Head;

		while (curr -> next) {
			curr = curr -> next;
		}

		curr -> next = temp;
		temp -> prev = curr;
		temp -> next = NULL;
	}

	return Head;
}

Node *insertAtAnyPoint(Node *Head, int pos) {
	Node *temp;
	temp = new Node(5);

	if (pos == 0) {
		if (Head == NULL) {
			temp -> next = NULL;
			temp -> prev = NULL;
			Head = temp;
		} else {
			Head -> prev = temp;
			temp -> next = Head;
			temp -> prev = NULL;
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
			temp -> next = NULL;
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
	// Head = insertAtAnyPoint(Head, 2);
	// Head = deleteStart(Head);
	// Head = deleteEnd(Head);
	Head = deleteAtAnyPoint(Head, 2);

	printLinkedList(Head);
}