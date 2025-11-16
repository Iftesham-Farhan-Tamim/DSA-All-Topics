// Print all Elements in Queue

#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int>q;
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);

    int n = q.size();

    while(n--) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }

    cout << endl;
    cout << q.size() << endl;
}

// output:
// 5 15 25 35 45 
// 5
// ............................................................................................
// Queue Reversal (https://www.geeksforgeeks.org/problems/queue-reversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Queue&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q) {
    stack<int> st;

    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    q = rev(q);

    cout << "\nReversed Queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

// output:
// Original Queue: 10 20 30 
// Reversed Queue: 30 20 10 
// ............................................................................................
// Reverse first K of a Queue (https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&difficulty%5B%5D=0&category%5B%5D=Queue&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>st;
    for(int i=0; i<k; i++) {
        st.push(q.front());
        q.pop();
    }

    int n = q.size();

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while(n--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;

    q = modifyQueue(q, k);

    cout << "Modified Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

// output:
// Modified Queue: 30 20 10 40 50 
// ............................................................................................
// TIme Needed To Buy Tickets (https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

#include<bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k) { 
    queue<int> q;
    int n = tickets.size();
    for(int i = 0; i < n; i++) {
        q.push(i);
    }

    int time = 0;

    while(tickets[k] != 0) {
        tickets[q.front()]--;
        if(tickets[q.front()]) {
            q.push(q.front());
        }
        
        q.pop();
        time++;
    }

    return time;
}

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    int result = timeRequiredToBuy(tickets, k);
    cout << "Time required to buy all tickets for person " << k << " = " << result << " seconds" << endl;
}

// output:
// Time required to buy all tickets for person 2 = 6 seconds
// ............................................................................................
// Implement stack using Queues (https://leetcode.com/problems/implement-stack-using-queues/description/)

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {

    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if(empty()) {
            return 0;
        } else if(!s2.empty()) {
            int element = s2.top();
            s2.pop();
            return element;
        } else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            int element = s2.top();
            s2.pop();
            return element;
        }
    }

    int peek() {
        if(empty()) {
            return 0;
        } else if(!s2.empty()) {
            return s2.top();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            return s2.top();
        }
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; 

    cout << "Popped: " << q.pop() << endl; 
    cout << "Popped: " << q.pop() << endl; 

    cout << "Front element now: " << q.peek() << endl; 

    q.push(40);
    q.push(50);

    while (!q.empty()) {
        cout << "Popped: " << q.pop() << endl;
    }

    // cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    if (q.empty()) {
        cout << "Is queue empty? Yes" << endl;
    } else {
        cout << "Is queue empty? No" << endl;
    }
}

// output:
// Front element: 10
// Popped: 10
// Popped: 20
// Front element now: 30
// Popped: 30
// Popped: 40
// Popped: 50
// Is queue empty? Yes
// ............................................................................................
// Implement Queue using Stacks (https://leetcode.com/problems/implement-queue-using-stacks/description/)

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

    void push(int x) {
        // base q1 q2 empty
        if(empty()) {
            q1.push(x);
        } else if(q1.empty()) {
            q2.push(x);
        } else {
            q1.push(x);
        }
    }

    int pop() {
        if(empty()) {
            return 0;
        } else if(q1.empty()) {
            while(q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }

            int element = q2.front();
            q2.pop();
            return element;
        } else {
            while(q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int top() {
        if(empty()) {
            return 0;
        } else if(q1.empty()) {
            return q2.back();
        } else {
            return q1.back();
        }
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  

    cout << "Popped: " << st.pop() << endl;       
    cout << "Popped: " << st.pop() << endl;       

    cout << "Top element now: " << st.top() << endl; 

    st.push(40);
    st.push(50);

    while (!st.empty()) {
        cout << "Popped: " << st.pop() << endl;
    }

    if (st.empty()) {
        cout << "Is stack empty? Yes" << endl;
    } else {
        cout << "Is stack empty? No" << endl;
    }
}

// output:
// Top element: 30
// Popped: 30
// Popped: 20
// Top element now: 10
// Popped: 50
// Popped: 40
// Popped: 10
// Is stack empty? Yes