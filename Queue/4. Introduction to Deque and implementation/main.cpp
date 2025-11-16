// Dequeue using linked list

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

class Dequeue {
    Node *front;
    Node *rear;

    public:

    Dequeue() {
        front = rear = NULL;
    }

    // push front
    void push_front(int x) {
        // empty
        if(front == NULL) {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of dequeue" << endl;
            return;
        } else {
            Node *temp = new Node(x);
            temp -> next = front;
            front -> prev = temp;
            front = temp;
            cout << "Pushed " << x << " in front of dequeue" << endl;
            return;
        }
    }

    // push back
    void push_back(int x) {
        // empty
        if(front == NULL) {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in back of dequeue" << endl;
            return;
        } else {
            Node *temp = new Node(x);
            rear -> next = temp;
            temp -> prev = rear;
            rear = temp;
            cout << "Pushed " << x << " in back of dequeue" << endl;
            return;
        }
    }

    // pop front
    void pop_front() {
        if(front == NULL) {
            cout << "Dequeue Underflow" << endl;
            return;
        } else {
            Node *temp = front;
            cout << "Popped " << temp -> data << " from front" << endl;
            front = front -> next;
            delete temp;
            
            if(front) {  // greater than 1 node
                front -> prev = NULL;
            } else {  // 1 node
                rear = NULL;
            }
        }
    }

    // pop back
    void pop_back() {
        if(front == NULL) {
            cout << "Dequeue Underflow" << endl;
            return;
        } else {
            Node *temp = rear;
            cout << "Popped " << temp -> data << " from back" << endl;
            rear = rear -> prev;
            delete temp;

            if(rear) {  // greater than 1 node
                rear -> next = NULL;
            } else {  // 1 node
                front = NULL;
            }
        }
    }

    // int start
    int start() {
        if(front == NULL) {
            return -1;
        } else {
            return front -> data;
        }
    }

    // end
    int end() {
        if(front == NULL) {
            return -1;
        } else {
            return rear -> data;
        }
    }
};

int main() {
    Dequeue d;
    d.push_back(5);
    d.push_front(8);
    cout << d.end() << endl;
    d.pop_back();
    d.pop_back();
    d.pop_back();
}

// output:
// Pushed 5 in back of dequeue
// Pushed 8 in front of dequeue
// Popped 5 from back
// 8
// ............................................................................................
// Dequeue using array

#include<bits/stdc++.h>
using namespace std;

class Dequeue {
    int front;
    int rear;
    int size;
    int *arr;

public:

    Dequeue(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return (rear + 1) % size == front;
    }

    void push_front(int x) {
        if(IsEmpty()) {  // empty
            front = rear = 0;
            cout << "Pushed " << x << " in front" << endl;
            arr[0] = x;
            return;
        } else if(IsFull()) {  // full
            cout << "Dequeue Overflow" << endl;
            return;
        } else {  // normal
            front = (front - 1 + size) % size;
            arr[front] = x;
            cout << "Pushed " << x << " in front" << endl;
            return;
        }
    }

    void push_back(int x) {
        // empty
        if(IsEmpty()) {
            front = rear = 0;
            cout << "Pushed " << x << " in back" << endl;
            arr[0] = x;
            return;
        } else if(IsFull()) {
            cout << "Dequeue Overflow" << endl;
            return;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " in back" << endl;
            return;
        }
    }

    void pop_front() {
        if(IsEmpty()) {
            cout << "Dequeue Underflow" << endl;
            return;
        } else {
            cout << "Popped " << arr[front] << " from dequeue" << endl;
            if(front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1)%size;
            }
        }
    }

    void pop_back() {
        if(IsEmpty()) {
            cout << "Dequeue Underflow" << endl;
            return;
        } else {
            cout << "Popped " << arr[rear] << " from dequeue" << endl;
            if(front == rear) {
                front = rear = -1;
            } else {
                rear = (rear - 1 + size) % size;
            }
        }
    }

    int start() {
        if(IsEmpty()) {
            return -1;
        } else {
            return arr[front];
        }
    }

    int end() {
        if((IsEmpty())) {
            return -1;
        } else {
            return arr[rear];
        }
    }
};

int main() {
    Dequeue d(5);
    d.push_back(10);
    d.push_back(91);
    d.push_back(9);
    d.push_front(18);
    d.pop_back();
    d.pop_front();
    cout << d.start() << endl;
}

// output:
// Pushed 10 in back
// Pushed 91 in back
// Pushed 9 in back
// Pushed 18 in front
// Popped 9 from dequeue
// Popped 18 from dequeue
// 10
// ............................................................................................
// creating dequeue using STL

#include<bits/stdc++.h>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_front(30);
    cout << d.front() << endl;
    d.pop_front();
    cout << d.front() << endl;
}

// output:
// 30
// 10