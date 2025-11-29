// AVL Tree Deletion (https://www.geeksforgeeks.org/problems/avl-tree-deletion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
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

Node *deleteNode(Node *root, int key) {
    if(!root) {
        return NULL;
    }

    if(key < root -> data) {
        root -> left = deleteNode(root -> left, key);
    } else if(key > root -> data) {
        root -> right = deleteNode(root -> right, key);
    } else {
        if(!root -> left && !root -> right) {
            delete root;
            return NULL;
        } else if(root -> left && !root -> right) {  //.
            Node *temp = root -> left;
            delete root;
            return temp;
        } else if(!root -> left && root -> right) {
            Node *temp = root -> right;
            delete root;
            return temp;
        } else {
            Node *curr = root -> right;
            while(curr -> left) {
                curr = curr -> left;
            }

            root -> data = curr -> data;
            root -> right = deleteNode(root -> right, curr -> data);
        }
    }

    // update the height
    root -> height = 1 + max(getheight(root -> left), getheight(root -> right));

    // check the balance
    int balance = getbalance(root);

    // left side
    if(balance > 1) {
        if(getbalance(root -> left) >= 0) {
            return rightRotation(root);
        } else {  // LR
            root -> left = leftRotation(root -> left);
            return rightRotation(root);
        }
    } else if(balance < -1) {  // right side
        if(getbalance(root -> right) <= 0) {
            return leftRotation(root);
        } else {
            root -> right = rightRotation(root -> right);
            return leftRotation(root);
        }
    }

    return root;
};

void inorder(Node* node) {
    if (!node) {
        return;
    }

    inorder(node -> left);
    cout << node -> data << " ";
    inorder(node -> right);
}

int main() {
    Node* root = NULL;

    root = new Node(30);
    root ->left = new Node(20);
    root -> right = new Node(40);
    root -> left -> left = new Node(10);
    root -> left -> right = new Node(25);

    root -> left -> left -> height = 1;
    root -> left -> right -> height = 1;
    root -> right -> height = 1;
    root -> left -> height = 1 + max(root -> left -> left -> height, root -> left -> right -> height);
    root -> right -> height = 1;
    root -> height = 1 + max(root -> left -> height, root -> right -> height);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 20);

    cout << "Inorder after deletion of 20: ";
    inorder(root);
    cout << endl;
}

// output:
// Inorder before deletion: 10 20 25 30 40 
// Inorder after deletion of 20: 10 25 30 40 