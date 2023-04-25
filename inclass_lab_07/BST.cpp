#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node* insertNode(struct node* root, int key) {
    if (root == NULL) {
        struct node* temp = new node();
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    } else if (root->key == key) {
        return root;
    } else if (root->key < key) {
        root->right = insertNode(root->right, key);
        return root;
    } else if (root->key > key) {
        root->left = insertNode(root->left, key);
        return root;
    }
    return root;
}

// Helper function to find the node with the minimum key in a subtree
struct node* findmin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (root->key < key) {
        root->right = deleteNode(root->right, key);
    } else if (root->key > key) {
        root->left = deleteNode(root->left, key);
    } else {
        // found the required node
        // case 1 (no children)
        if (root->left == NULL && root->right == NULL) {
            delete(root);
            return NULL;
        }
        // case 2 (one child)
        else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            delete(temp);
            return root;
        } else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            delete(temp);
            return root;
        }
        // case 3 (2 children)
        else {
            struct node* temp = findmin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
            delete(temp);
            return root;
        }
    }
    return root;
}

// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
        cin >> operation;
    }
  
    traverseInOrder(root);
    return 0;
}
