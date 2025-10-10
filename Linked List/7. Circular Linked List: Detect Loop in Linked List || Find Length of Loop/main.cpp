// detect loop in linked list

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

    Node *temp = new Node(arr[idx]);
    temp -> next = createLinkedList(arr, idx+1, size);
    return temp;
}

bool check(vector<Node*>&visited, Node *curr) {
    for(int i = 0; i < visited.size(); i++) {
        if(visited[i] == curr) {
            return 1;
        }
    }

    return 0;
}

bool deleteLoop(Node *Head) {
    Node *curr = Head;
    vector<Node*>visited;

    while(curr != NULL) {
        if(check(visited, curr)) {
            return 1;
        }

        visited.push_back(curr);
        curr = curr -> next;
    }

    return 0;
}

void printLinkedList(Node *Head) {
    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5);

    Node *temp = Head;
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = Head->next;

    if(deleteLoop(Head)) {
        cout << "Loop detected";
    } else {
        cout << "No loop";
    }
}

// output:
// Loop detected
// ............................................................................................
// detect loop in linked list (using unordered map)

#include<bits/stdc++.h>
#include <unordered_map> 
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

    Node *temp = new Node(arr[idx]);
    temp -> next = createLinkedList(arr, idx+1, size);
    return temp;
}

bool deleteLoop(Node *Head) {
    Node *curr = Head;
    unordered_map<Node*, bool> visited;

    while(curr) {
        if(visited[curr] == 1) {
            return 1;
        }

        visited[curr] = 1;
        curr = curr -> next;
    }

    return 0;
}

void printLinkedList(Node *Head) {
    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    Node *Head = NULL;
    int arr[] = {2, 4, 6, 8, 10};

    Head = createLinkedList(arr, 0, 5);

    Node *temp = Head;
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = Head->next;

    if(deleteLoop(Head)) {
        cout << "Loop detected";
    } else {
        cout << "No loop";
    }
}

// output:
// Loop detected and removed
// ............................................................................................
// detect loop using slow and fast pointer (https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

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
	if (idx == size) {
		return NULL;
	}

	Node *temp;
	temp = new Node(arr[idx]);
	temp -> next = createLinkedList(arr, idx + 1, size);
	return temp;
}

bool detectLoop(Node *Head) {
	Node *slow = Head, *fast = Head;

	while (fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;

		if (slow == fast) {
			return 1;
		}
	}

	return 0;
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
	Head = createLinkedList(arr, 0, 5);

	Node *temp = Head;
	while (temp -> next) {
		temp = temp -> next;
	}

	temp -> next = Head -> next;

	if (detectLoop(Head)) {
		cout << "Loop detected";
	} else {
		cout << "No loop";
	}
}

// output:
// Loop detected
// ............................................................................................
// Find length of loop using slow and fast pointer (https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

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

    Node *temp = new Node(arr[idx]);
    temp -> next = createLinkedList(arr, idx+1, size);
    return temp;
}

int countNodesinLoop(Node *Head) {
    Node *slow = Head, *fast = Head;

    while(fast!=NULL && fast -> next!=NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            break;
        }
    }

    if(fast == NULL || fast -> next == NULL) {
        return 0;
    }

    int count = 1;
    slow = fast -> next;

    while(slow != fast) {
        count++;
        slow = slow -> next;
    }

    return count;
}

void printLinkedList(Node *Head) {
    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    Node *Head = NULL;
    int arr[] = {2, 4, 6, 8, 10};

    Head = createLinkedList(arr, 0, 5);

    Node *temp = Head;
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = Head->next; 

    cout << "Number of nodes in loop: " << countNodesinLoop(Head) << endl;
}

// output:
// Number of nodes in loop: 4