// remove duplicate element from list (https://www.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1)

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

Node *removeDuplicates(Node *Head) {
    vector<int> ans;
    ans.push_back(Head -> data);

    Node *curr = Head -> next;

    while(curr) {
        if(ans[ans.size()-1]!=curr -> data) {
            ans.push_back(curr -> data);
        }

        curr = curr -> next;
    }

    curr = Head;
    int index = 0;
    Node *prev = NULL;

    while(index<ans.size()) {
        curr -> data = ans[index++];
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = NULL;
    return Head;
}

int main() {
    Node *Head = NULL;
    
    int arr[] = {2, 2, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    Head = removeDuplicates(Head);

    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 6 8 10
// ............................................................................................
// remove duplicate element from list (https://www.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1)

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

Node *removeDuplicates(Node *Head) {
    Node *curr = Head -> next, *prev = Head;

    while(curr) {
        if(curr -> data == prev -> data) {
            prev -> next = curr -> next;
            delete curr;
            curr = prev -> next;
        } else {
            prev = prev -> next;
            curr = curr -> next;
        }
    }

    return Head;
}

int main() {
    Node *Head;
    Head = NULL;

    int arr[] = {2, 2, 6, 8, 10};
    Head = createLinkedList(arr, 0, 5, NULL);

    Head = removeDuplicates(Head);

    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 2 6 8 10
// ............................................................................................
// merge two sorted linked list (https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

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

Node *sortedMerge(Node *Head1, Node *Head2) {
    Node *Head = new Node(0);
    Node *Tail = Head;

    while(Head1&&Head2) {
        if(Head1 -> data <= Head2 -> data) {
            Tail -> next = Head1;
            Head1 = Head1 -> next;
            Tail = Tail -> next;
            Tail -> next = NULL;
        } else {
            Tail -> next = Head2;
            Head2 = Head2 -> next;
            Tail = Tail -> next;
            Tail -> next = NULL;
        }
    }

    if(Head1) {
        Tail -> next = Head1;
    } else {
        Tail -> next = Head2;
    }

    Tail = Head;
    Head = Head -> next;
    delete Tail;

    return Head;
}

int main() {
    Node *Head1, *Head2;
    Head1 = Head2 = NULL;

    int arr1[] = {2, 4, 6, 8, 10};
    int arr2[] = {1, 3, 5, 7, 9};
    Head1 = createLinkedList(arr1, 0, 5, NULL);
    Head2 = createLinkedList(arr2, 0, 5, NULL);

    Node *merged = sortedMerge(Head1, Head2);

    Node *temp;
    temp = merged;
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 1 2 3 4 5 6 7 8 9 10
// ............................................................................................
// sort a linked list which contain 0 1 2 (https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

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

Node *sortLinkedList(Node *Head) {
    Node *curr = Head;
    int count0 = 0, count1 = 0, count2 = 0;

    while(curr) {
        if(curr -> data == 0) {
            count0++;
        } else if(curr -> data == 1) {
            count1++;
        } else {
            count2++;
        }

        curr = curr -> next;
    }

    curr = Head;

    while(count0--) {
        curr -> data = 0;
        curr = curr -> next;
    }

    while(count1--) {
        curr -> data = 1;
        curr = curr -> next;
    }

    while(count2--) {
        curr -> data = 2;
        curr = curr -> next;
    }

    return Head;
}

int main() {
    Node *Head;
    Head = NULL;

    int arr[] = {0, 1, 0, 2, 2, 0, 1};
    Head = createLinkedList(arr, 0, 7, NULL);

    Head = sortLinkedList(Head);

    Node *temp;
    temp = Head;

    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// output:
// 0 0 0 1 1 2 2