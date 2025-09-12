// Remove Nth Node From End of List (https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

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

void printList(Node* Head) {
    Node* temp;
    temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Remove N-th node from end (two-pass method)
Node* removeNthFromEnd(Node* Head, int n) {
    int count = 0;
    Node* temp = Head;

    // Count total nodes
    while (temp) {
        count++;
        temp = temp->next;
    }

    count -= n;

    // If we need to remove the head
    if (count == 0) {
        temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    }

    Node* curr = Head;
    Node* prev = NULL;

    // Move to the node before the one to delete
    while (count--) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return Head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {2, 4, 6, 8, 10};
    Node* Head = CreateLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printList(Head);
    cout << endl;

    int n = 3; // Example: remove 3rd node from end
    Head = removeNthFromEnd(Head, n);

    cout << "After removing " << n << "-th node from end: ";
    printList(Head);
}

// output:
// Original List: 2 4 6 8 10
// After removing 3-th node from end: 2 4 8 10
// ............................................................................................
// Remove every k'th node (https://www.geeksforgeeks.org/problems/remove-every-kth-node/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

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
    if (idx == size) return NULL;

    Node* temp = new Node(arr[idx]);
    temp->next = CreateLinkedList(arr, idx + 1, size);
    return temp;
}

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete every k-th node
Node* deleteK(Node* Head, int k) {
    if (k == 1) {  // delete all nodes
        return NULL; 
    }

    Node* curr = Head;
    Node* prev = NULL;
    int count = 1;

    while (curr) {
        if (count == k) {
            Node* temp = curr;
            prev->next = curr->next;
            curr = prev->next;
            delete temp;
            count = 1;
        } else {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }

    return Head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {2, 4, 6, 8, 10};
    Node* Head = CreateLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printList(Head);

    int k = 2; // delete every 3rd node
    Head = deleteK(Head, k);

    cout << "After deleting every " << k << "-th node: ";
    printList(Head);
}

// output:
// Original List: 2 4 6 8 10
// After deleting every 3-th node: 2 6 10
// ............................................................................................
// Rotate List (https://leetcode.com/problems/rotate-list/description/)

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

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Rotate linked list to the right by k positions
Node* rotateRight(Node* Head, int k) {
    if (Head == NULL || Head->next == NULL) {
        return Head;
    }

    // Count number of nodes
    int count = 0;
    Node* temp = Head;
    while (temp) {
        count++;
        temp = temp -> next;
    }

    k = k % count;
    if (k == 0) {
        return Head;
    }
 
    // Find new head
    int steps = count - k;
    Node* curr = Head;
    Node* prev = NULL;
    while (steps--) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;  // Break the list
    Node* Tail = curr;
    while (Tail->next != NULL) {
        Tail = Tail->next;
    }

    Tail->next = Head;  // Attach old head to the tail
    Head = curr;        // Update head

    return Head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {2, 4, 6, 8, 10};
    Node* Head = CreateLinkedList(arr, 0, 5);

    cout << "Original List: ";
    printList(Head);

    int k = 2; // Rotate right by 2 positions
    Head = rotateRight(Head, k);

    cout << "After rotating by " << k << " positions: ";
    printList(Head);
}

// output:
// Original List: 2 4 6 8 10
// After rotating by 2 positions: 8 10 2 4 6
// ............................................................................................
// Palindrome Linked List (https://leetcode.com/problems/palindrome-linked-list/description/)

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

Node *CreateLinkedList(int arr[], int idx, int size) {
    if (idx == size) {
        return NULL;
    }
    
    Node *temp;
    temp = new Node(arr[idx]);
    temp->next = CreateLinkedList(arr, idx + 1, size);
    
    return temp;
}

void printList(Node *Head) {
    Node *temp;
    temp = Head;
    
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Check palindrome
bool isPalindrome(Node *Head) {
    if (Head->next == NULL) {
        return 1;
    }
    
    int count = 0;
    Node *temp;
    temp = Head;
    
    while (temp) {
        count++;
        temp = temp->next;
    };
    
    count /= 2;
    Node *curr = Head, *prev = NULL;
    
    // Skip number of nodes
    while (count--) {
        prev = curr;
        curr = curr->next;
    };
    
    prev->next = NULL;
    
    // reverse the second linked list, curr is pointing
    Node *front;
    prev = NULL;
    
    while (curr) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    
    // prev is pointing to second list
    // head is pointing to first list
    
    Node *Head1 = Head, *Head2 = prev;
    // check palindrome
    
    while (Head1) {
        if (Head1->data != Head2->data) {
            return 0;
        }
        
        Head1 = Head1->next;
        Head2 = Head2->next;
    }
    
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int arr[] = {2, 4, 6, 4, 2};
    Node *Head = CreateLinkedList(arr, 0, 5);
    
    printList(Head);
    
    if (isPalindrome(Head)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }
}

// output:
// 2 4 6 4 2 
// Palindrome
// ............................................................................................
// Reverse a Doubly Linked List (https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include <bits/stdc++.h>
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

    Node *temp = new Node(arr[idx]);
    temp->prev = back;
    temp->next = createLinkedList(arr, idx + 1, size, temp);

    return temp;
}

Node* reverseDLL(Node* head) {
    if (!head || !head->next) return head; // empty or single node

    Node* curr = head;
    Node* temp = NULL;

    while (curr) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to "next" (which is actually prev after swap)
        curr = curr->prev;
    }

    // After loop, temp points to the node before new head
    if (temp) {
        head = temp->prev;
    }
    return head;
}

int main() {
    Node *Head = NULL;
    int arr[] = {2, 4, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    Head = reverseDLL(Head);

    Node *temp;
    temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// output:
// 10 8 6 4 2