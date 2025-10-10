// Remove loop in linked list (Method 1)

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

void removeLoop(Node* Head) {
    Node *slow = Head, *fast = Head;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            break;
        }
    }

    if(fast == NULL || fast -> next == NULL) {
        return;
    }

    slow = Head;

    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    while(slow -> next != fast) {
        slow = slow -> next;
    }

    slow -> next = NULL;
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

    removeLoop(Head); 
    printLinkedList(Head);
}

// output:
// 2 4 6 8 10
// //............................................................................................
// Remove loop in linked list (Method 2)

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

void removeLoop(Node *Head) {
    Node *slow = Head, *fast = Head;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            break;
        }
    }

    if(!fast || !fast -> next) {
        return;
    }

    slow = fast -> next;
    int count = 1;

    while(slow != fast) {
        count++;
        slow = slow -> next;
    }

    slow = Head, fast = Head;

    while(count--) {
        fast = fast -> next;
    }

    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    while(slow -> next != fast) {
        slow = slow -> next;
    }

    slow -> next = NULL;
}

void printLinkedlist(Node *Head) {
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

    Node* temp = Head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = Head->next;

    removeLoop(Head); 

    printLinkedlist(Head); 
}

// output:
// 2 4 6 8 10
// ............................................................................................
// Intersection point in Y shaped linked list (https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article)

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

int intersectPoint(Node *Head1, Node *Head2) {
    Node *curr1 = Head1, *curr2 = Head2;
    int count1 = 0, count2 = 0;

    while(curr1) {
        count1++;
        curr1 = curr1 -> next;
    }

    while(curr2) {
        count2++;
        curr2 = curr2 -> next;
    }

    curr1 = Head1, curr2 = Head2;

    while(count1 > count2) {
        count1--;
        curr1 = curr1 -> next;
    }

    while(count1 < count2) {
        count2--;
        curr2 = curr2 -> next;
    }

    while(curr1 != curr2) {
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }

    if(!curr1) {
        return -1;
    }

    return curr1 -> data;
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
    Node *Head1 = NULL;
    int arr1[] = {1, 2, 3, 4, 5};
    Head1 = createLinkedList(arr1, 0, 5);

    Node *Head2 = NULL;
    int arr2[] = {9, 10};
    Head2 = createLinkedList(arr2, 0, 2);

    // Make the second list intersect with the first at node with value 4
    Node* temp = Head1;
    while(temp->data != 4) { // move to node 4 in first list
        temp = temp->next;
    }

    Node* temp2 = Head2;
    while(temp2->next) { // move to last node of second list
        temp2 = temp2->next;
    }

    // Point last node of second list to node 4 of first list
    temp2->next = temp;

    // Find intersection
    cout << "Intersection at node: " << intersectPoint(Head1, Head2) << endl; // Output: 4
}

// output:
// Intersection at node: 4
// ............................................................................................
// Intersection point in Y shaped linked list (alternate solution)

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

int intersectPoint(Node *Head1, Node *Head2) {
    Node *curr1 = Head1;

    while(curr1 -> next) {
        curr1 = curr1 -> next;
    }

    curr1 -> next = Head1;

    Node *slow = Head2, *fast = Head2;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            break;
        }
    }

    if(!fast || !fast -> next) {
        return -1;
    }

    slow = Head2;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow -> data;
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
    int arr1[] = {2, 4, 6, 8, 10};
    Node *Head1 = createLinkedList(arr1, 0, 5);

    int arr2[] = {20, 30};
    Node *Head2 = createLinkedList(arr2, 0, 2);

    Head2->next->next = Head1->next->next;

    int ans = intersectPoint(Head1, Head2);
    if(ans == -1) cout << "No intersection\n";
    else cout << "Intersection at node with data: " << ans << endl;
}

// output:
// Intersection at node with data: 6