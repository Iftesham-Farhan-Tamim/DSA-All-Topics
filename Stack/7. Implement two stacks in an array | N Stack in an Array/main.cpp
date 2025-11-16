// Two Stacks in an Array (https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)

#include<bits/stdc++.h>
using namespace std;

class twoStacks {
    public:
    int *arr;
    int top1, top2;
    int size;

    twoStacks(int n) {
        arr = new int[n];
        size = n;
        top1 = - 1;
        top2 = n;
    }

    void push1(int x) {
        if(top1 + 1 == top2) {
            return;
        }

        top1++;
        arr[top1] = x;
    }

    void push2(int x) {
        if(top2 - 1 == top1) {
            return;
        }

        top2--;
        arr[top2] = x;
    }

    int pop1() {
        if(top1 == -1) {
            return -1;
        }

        int element = arr[top1];
        top1--;
        return element;
    }

    int pop2() {
        if(top2 == size) {
            return -1;
        }

        int element = arr[top2];
        top2++;
        return element;
    }
};

int main() {
    twoStacks ts(5);  
    ts.push1(2);     
    ts.push1(3);      
    ts.push2(4);      

    cout << ts.pop1() << " ";  
    cout << ts.pop2() << " "; 
    cout << ts.pop2() << " ";  
}

// output:
// 3 4 -1
// ............................................................................................
// N Stacks In An Array (https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271?leftPanelTabValue=PROBLEM)

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int index;
    Node *next;

    Node(int x) {
        index = x;
        next = NULL;
    }
};

class NStack {
    public:
    stack<int>st;
    int *arr;
    Node **top;

    NStack(int n, int s) {
        arr = new int[s];
        top = new Node*[n];
        for(int i = 0; i < n; i++) {
            top[i] = NULL;
        }

        for(int i = 0; i < s; i++) {
            st.push(i);
        }
    }

    bool push(int x, int m) {
        if(st.empty()) {
            return 0;
        }

        arr[st.top()] = x;
        Node *temp = new Node(st.top());
        temp -> next = top[m - 1];
        top[m - 1] = temp;
        st.pop();
        return 1;
    }

    int pop(int m) {
        if(top[m - 1] == NULL) {
            return -1;
        }

        int element = arr[top[m - 1] ->index];
        st.push(top[m - 1]->index);
        top[m - 1] = top[m - 1]->next;
        return element;
    }
};

int main() {
    NStack ns(3, 10);

    ns.push(5, 1);
    ns.push(15, 1);
    ns.push(25, 2);

    cout << ns.pop(1) << endl;  
    cout << ns.pop(1) << endl;  
    cout << ns.pop(2) << endl;  
}

// output:
// 15
// 5
// 25