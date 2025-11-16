// Implement Queue using array (https://www.geeksforgeeks.org/problems/implement-queue-using-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size;

    public:

    // constructor
    Queue(int n) {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    // if queue is empty or not

    bool IsEmpty() {
        return front == -1;
    }

    // queue us full or not
    bool IsFull() {
        return rear == size - 1;
    }

    // push element into queue, end

    void push(int x) {
        if(IsEmpty()) {  // empty
            cout << "Pushed " << x << " into the queue" << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        } else if(IsFull()) {  // full
            cout << "Queue Overflow" << endl;
            return;
        } else {  // insert
            rear = rear + 1;
            arr[rear] = x;
            cout << "Pushed " << x << " into the queue" << endl;
        }
    }

    void pop() {
        // empty
        if(IsEmpty()) {
            cout << "Queue UnderFlow" << endl;
            return;
        } else {
            if(front == rear) {
                cout << "Popped " << arr[front] << " into the queue" << endl;
                front = rear = -1;
            } else {
                cout << "Popped " << arr[front] << " into the queue" << endl;
                front = front + 1;
            }
        }
    }

    int start() {
        if(IsEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q(5);
    q.push(5);
    q.push(15);
    q.push(51);
    q.pop();
    q.pop();
    // cout << q.start() << endl;
    int x = q.start();
    if(!q.IsEmpty()) {
        cout << x << " ";
    }
}

// output:
// Pushed 5 into the queue
// Pushed 15 into the queue
// Pushed 51 into the queue
// Popped 5 into the queue
// Popped 15 into the queue
// 51
// ............................................................................................
// Implement Queue using Linked List (https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

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

class Queue {
    Node *front;
    Node *rear;

    public:

    Queue() {
        front = rear = NULL;
    }

    // queue is empty or not
    bool IsEmpty() {
        return front == NULL;
    }

    // push element into the queue
    void push(int x) {
        if(IsEmpty()) {  // if empty
            cout << "Pushed " << x << " into the queue" << endl;
            front = rear = new Node(x);
            return;
        } else {  // if not empty
            rear -> next = new Node(x);
            if(rear -> next == NULL) {
                cout << "Queue Overflow" << endl;
                return;
            }
            cout << "Pushed " << x << " into the queue" << endl;
            rear = rear -> next;
        }
    }

    void pop() {
        if(IsEmpty()) {
            cout << "Queue Under" << endl;
            return;
        } else {
            cout << "Popped " << front -> data << " from the queue" << endl;
            Node *temp = front;
            front = front -> next;
            delete temp;
        }
    }

    int start() {
        if(IsEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return front -> data;
        }
    }
};

int main() {
    Queue q;
    q.push(5);
    q.push(51);
    q.push(115);
    q.push(58);
    q.pop();
    cout << q.start() << endl;
}

// output:
// Pushed 5 into the queue
// Pushed 51 into the queue
// Pushed 115 into the queue
// Pushed 58 into the queue
// Popped 5 from the queue
// 51
// ............................................................................................
// Implementing STL(Implementing STL (Standard Template Library))

#include <bits/stdc++.h>
using namespace std;

int main() {
    // how to create a queue
    queue<int>q;
    q.push(10);
    q.push(40);
    q.push(123);

    // delete
    q.pop();

    // front element
    cout << q.front() << endl;

    // back element
    cout << q.back() << endl;

    cout << q.size() << endl;

    // empty
    cout << q.empty() << endl;
}

// 40
// 123
// 2
// 0