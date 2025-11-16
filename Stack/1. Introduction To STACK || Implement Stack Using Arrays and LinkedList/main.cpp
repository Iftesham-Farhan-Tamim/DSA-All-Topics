// Stack using Array

#include<bits/stdc++.h>
using namespace std;

class Stack {
    int *arr;
    int size;
    int top;

    public:

    bool flag;

    // constructor
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
    }

    // push
    void push(int value) {
        if(top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        } else {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " into the stack" << endl;
            flag = 0;
        }
    }
    // pop
    void pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "Popped " << arr[top] << " from the stack" << endl;
            top--;
            if(top == -1) {
                flag = 1;
            }
        }
    }
    // peek
    int peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }
    // IsEmpty
    bool IsEmpty() {
        return top == -1;
    }
    // IsSize
    int IsSize() {
        return top + 1;
    }
};

int main() {
    Stack S(5);
    S.push(5);
    S.push(6);
    S.push(8);
    cout << S.peek() << endl;
    S.pop();
    cout << S.IsEmpty() << endl;
    cout << S.IsSize() << endl;
}

// output:
// Pushed 5 into the stack
// Pushed 6 into the stack
// Pushed 8 into the stack
// 8
// Popped 8 from the stack
// 0
// 2
// ............................................................................................
// Stack Using LinkedLists

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

class Stack {
    Node *top;
    int size;

    public:

    Stack() {
        top = NULL;
        size = 0;
    }

    // push
    void push(int value) {
        Node *temp = new Node(value);
        if(temp == NULL) {
            cout << "Stack Overflow" << endl;
            return;
        } else {
            temp -> next = top;
            top = temp;
            size++;
            cout << "Pushed " << value << " into the stack" << endl;
        }
    }
    // pop
    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        } else {
            Node *temp = top;
            cout << "Popped " << top -> data << " from the stack" << endl;
            top = top -> next;
            delete temp;
            size--;
        }
    }
    // peek
    int peek() {
        if(top == NULL) {
            cout << "Stack is Empty" << endl;
            return -1;
        } else {
            return top -> data;
        }
    }
    // IsEmpty
    bool IsEmpty() {
        return top == NULL;
    }
    // IsSize
    int IsSize() {
        return size;
    }
};

int main() {
    Stack S;
    S.push(6);
    S.push(16);
    S.push(62);
    S.push(86);
    S.pop();
    cout << S.IsEmpty() << endl;
}

// output:
// Pushed 6 into the stack
// Pushed 16 into the stack
// Pushed 62 into the stack
// Pushed 86 into the stack
// Popped 86 from the stack
// 0
// ............................................................................................
// Stack using STL 

#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> S;
    S.push(6);
    S.push(16);
    S.push(26);
    cout << S.size() << endl;
    // top
    S.pop();
    cout << S.top() << endl;
    cout << S.empty() << endl;
}

// output:
// 3
// 16
// 0