// Merge two binary Max heaps (https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1?page=1&difficulty%5B%5D=0&category%5B%5D=Heap&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &ans, int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && ans[left] > ans[largest]) {
        largest = left;
    }

    if(right < n && ans[right] > ans[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(ans[largest], ans[index]);
        Heapify(ans, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        ans.push_back(a[i]);
    }

    for(int i = 0; i < m; i++) {
        ans.push_back(b[i]);
    }

    n = ans.size();
    for(int i = n / 2 - 1; i >= 0; i++) {
        Heapify(ans, i, n);
    }

    return ans;
}

int main() {
    vector<int> a;
    a.push_back(10);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);

    vector<int> b;
    b.push_back(12);
    b.push_back(7);
    b.push_back(9);

    vector<int> result = mergeHeaps(a, b, a.size(), b.size());

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

// output:
// 12 10 9 2 5 7 6
// ............................................................................................
// Is Binary Tree Heap (https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int count(Node *root) {
    if(!root) {
        return 0;
    }

    return 1 + count(root -> left) + count(root -> right);
}

bool CBT(Node *root, int index, int total_nodes) {
    if(!root) {
        return 1;
    }

    if(index >= total_nodes) {
        return 0;
    }

    return CBT(root -> left, 2 * index + 1, total_nodes) && 
           CBT(root -> right, 2 * index + 2, total_nodes);    
}

bool MaxHeap(Node *root) {
    if(root -> left) {
        if(root -> data < root -> left -> data) {
            return 0;
        }

        if(!MaxHeap(root -> left)) {
            return 0;
        }
    }

    if(root -> right) {
        if(root -> data < root -> right -> data) {
            return 0;
        }

        return MaxHeap(root -> right);
    }

    return 1;
}

bool isHeap(struct Node *tree) {
    int num = count(tree);

    if(!CBT(tree, 0, num)) {
        return 0;
    }

    return MaxHeap(tree);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    if (isHeap(root)) {
        cout << "YES, it is a max heap" << endl;
    } else {
        cout << "NO, it is NOT a max heap" << endl;
    }
}

// output:
// YES, it is a max heap
// ............................................................................................
// BST to max heap (https://www.geeksforgeeks.org/problems/bst-to-max-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;       
        left = NULL;      
        right = NULL;     
    }
};

void inorder(Node *root, vector<int> &ans) {
    if(!root) {
        return;
    }

    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
}

void postOrder(Node *root, vector<int> &ans, int &index) {
    if(!root) {
        return;
    }

    postOrder(root -> left, ans, index);
    postOrder(root -> right, ans, index);
    root -> data = ans[index];
    index++;
}

void convertToMaxHeapUtil(Node *root) {
    vector<int> ans;
    inorder(root, ans);

    int index = 0;
    postOrder(root, ans, index);
}

void printPost(Node* root) {
    if(!root) {
        return;
    }
    
    printPost(root -> left);
    printPost(root -> right);
    cout << root -> data << " ";
}

int main() {
    Node *root = new Node(4);
    Node *n1 = new Node(2);
    Node *n2 = new Node(6);
    Node *n3 = new Node(1);
    Node *n4 = new Node(3);
    Node *n5 = new Node(5);
    Node *n6 = new Node(7);

    root -> left = n1; root -> right = n2;
    n1 -> left = n3; n1 -> right = n4;
    n2 -> left = n5; n2 -> right = n6;

    convertToMaxHeapUtil(root);
    printPost(root);
}

// output:
// 1 2 3 4 5 6 7