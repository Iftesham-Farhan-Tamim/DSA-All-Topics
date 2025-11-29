// Adelson-Velsky and Landis Tree (AVL)

// AVL Tree Insertion with Rotations

// Problem type: Self-Balancing BST / AVL Tree insertion
// Algorithm approach: Recursive BST insertion + height update + rotations (LL, RR, LR, RL)
// Goal: Keep tree height O(log n) after every insertion

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getheight(Node *root) {
    if(!root) {
        return 0;
    }

    return root -> height;
};

int getbalance(Node *root) {
    return getheight(root -> left) - getheight(root -> right);
};

Node *rightRotation(Node *root) {  // right rotation
    Node *child = root -> left;
    Node *childRight = child -> right;

    child -> right = root;
    root -> left = childRight;

    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left), getheight(child -> right));

    return child;
}

Node *leftRotation(Node *root) {  // right rotation
    Node *child = root -> right;
    Node *childLeft = child -> left;

    child -> left = root;
    root -> right = childLeft;

    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left), getheight(child -> right));

    return child;
}

Node *insert(Node *root, int key) {
    if(!root) {
        return new Node(key);
    }

    if(key < root -> data) {
        root -> left = insert(root -> left, key);
    } else if(key > root -> data) {
        root -> right = insert(root -> right, key);
    } else {
        return root;
    }

    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));
    int balance = getbalance(root);  // Balance check

    if(balance > 1 && key < root -> left -> data) {  // Left Left case
        return rightRotation(root);
    } else if(balance < -1 && root -> right -> data < key) {  // Right Right case
        return leftRotation(root);
    } else if(balance > 1 && key > root -> left -> data) {  // Left Right case
        root -> left = leftRotation(root -> left);
        return rightRotation(root);
    } else if(balance < -1 && root -> right -> data > key) {  // Right Left case
        root -> right = rightRotation(root -> right);
        return leftRotation(root);
    } else {  // no unbalancing
        return root;
    }
}

void preorder(Node *root) {
    if(!root) {
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node *root) {
    if(!root) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main() {
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "precoder: " << endl;
    preorder(root);

    cout << endl;

    cout << "inorder: " << endl;
    inorder(root);
}

// output:
// precoder: 
// 20 10 5 50 30 95 70 100 
// inorder: 
// 5 10 20 30 50 70 95 100
// ............................................................................................
// Insertion in AVL Tree (https://www.geeksforgeeks.org/problems/avl-tree-insertion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article)

#include <bits/stdc++.h>
using namespace std;

// ---------------- Node Class ----------------
class Node {
public:
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

// ---------------- Helper Functions ----------------
int getheight(Node *root) {
    if(!root) {
        return 0;
    }

    return root -> height;
};

int getbalance(Node *root) {
    return getheight(root -> left) - getheight(root -> right);
};

Node *rightRotation(Node *root) {  // right rotation
    Node *child = root -> left;
    Node *childRight = child -> right;

    child -> right = root;
    root -> left = childRight;

    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left), getheight(child -> right));

    return child;
}

Node *leftRotation(Node *root) {  // right rotation
    Node *child = root -> right;
    Node *childLeft = child -> left;

    child -> left = root;
    root -> right = childLeft;

    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left), getheight(child -> right));

    return child;
}

// ---------------- AVL Insert Function ----------------
Node *insertToAVL(Node *root, int key) {
    if(!root) {
        return new Node(key);
    }

    if(key < root -> data) {
        root -> left = insertToAVL(root -> left, key);
    } else if(key > root -> data) {
        root -> right = insertToAVL(root -> right, key);
    } else {
        return root;
    }

    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));
    int balance = getbalance(root);  // Balance check

    if(balance > 1 && key < root -> left -> data) {  // Left Left case
        return rightRotation(root);
    } else if(balance < -1 && root -> right -> data < key) {  // Right Right case
        return leftRotation(root);
    } else if(balance > 1 && key > root -> left -> data) {  // Left Right case
        root -> left = leftRotation(root -> left);
        return rightRotation(root);
    } else if(balance < -1 && root -> right -> data > key) {  // Right Left case
        root -> right = rightRotation(root -> right);
        return leftRotation(root);
    } else {  // no unbalancing
        return root;
    }
}

// ---------------- Traversals ----------------
void preorder(Node *root) {
    if(!root) {
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node *root) {
    if(!root) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

// ---------------- Main Function ----------------
int main() {
    Node* root = NULL;

    vector<int> keys = {10, 20, 30, 50, 70, 5, 100, 95};

    for(int i = 0; i < keys.size(); i++) {
        int key = keys[i];
        root = insertToAVL(root, key);
    }

    cout << "Preorder traversal (shows structure): ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal (sorted keys): ";
    inorder(root);
    cout << endl;
}

// output:
// Preorder traversal (shows structure): 20 10 5 50 30 95 70 100 
// Inorder traversal (sorted keys): 5 10 20 30 50 70 95 100 