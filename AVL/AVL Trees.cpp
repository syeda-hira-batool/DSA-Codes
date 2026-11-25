#include <iostream>
using namespace std;

class Node {
	public:
	    int data;
	    Node* left;
	    Node* right;
	    int height;
	
	    Node(int value) {
	        data = value;
	        left = right = NULL;
	        height = 1;
	    }
};

class AVL {
	public:
	
	    // Get height
	    int getHeight(Node* root) {
	        if (root == NULL)
	            return 0;
	
	        return root->height;
	    }
	
	    // Get balance factor
	    int getBalance(Node* root) {
	        if (root == NULL)
	            return 0;
	
	        return getHeight(root->left) -
	               getHeight(root->right);
	    }
	
	    // Right Rotation
	    Node* rightRotate(Node* y) {
	        Node* x = y->left;
	        Node* T2 = x->right;
	
	        x->right = y;
	        y->left = T2;
	
	        y->height = 1 + max(getHeight(y->left),
	                            getHeight(y->right));
	
	        x->height = 1 + max(getHeight(x->left),
	                            getHeight(x->right));
	
	        return x;
	    }
	
	    // Left Rotation
	    Node* leftRotate(Node* x) {
	        Node* y = x->right;
	        Node* T2 = y->left;
	
	        y->left = x;
	        x->right = T2;
	
	        x->height = 1 + max(getHeight(x->left),
	                            getHeight(x->right));
	
	        y->height = 1 + max(getHeight(y->left),
	                            getHeight(y->right));
	
	        return y;
	    }
	
	    // Insert
	    Node* insert(Node* root, int value) {
	
	        if (root == NULL)
	            return new Node(value);
	
	        if (value < root->data)
	            root->left = insert(root->left, value);
	
	        else if (value > root->data)
	            root->right = insert(root->right, value);
	
	        else
	            return root;
	
	        // Update height
	        root->height = 1 + max(getHeight(root->left),
	                               getHeight(root->right));
	
	        int balance = getBalance(root);
	
	        // LL Case
	        if (balance > 1 && value < root->left->data)
	            return rightRotate(root);
	
	        // RR Case
	        if (balance < -1 && value > root->right->data)
	            return leftRotate(root);
	
	        // LR Case
	        if (balance > 1 && value > root->left->data) {
	            root->left = leftRotate(root->left);
	            return rightRotate(root);
	        }
	
	        // RL Case
	        if (balance < -1 && value < root->right->data) {
	            root->right = rightRotate(root->right);
	            return leftRotate(root);
	        }
	
	        return root;
	    }
	
	    // Find minimum node
	    Node* findMin(Node* root) {
	        while (root->left != NULL)
	            root = root->left;
	
	        return root;
	    }
	
	    // Delete
	    Node* deleteNode(Node* root, int value) {
	
	        if (root == NULL)
	            return root;
	
	        if (value < root->data)
	            root->left = deleteNode(root->left, value);
	
	        else if (value > root->data)
	            root->right = deleteNode(root->right, value);
	
	        else {
	
	            // No child or one child
	            if (root->left == NULL ||
	                root->right == NULL) {
	
	                Node* temp = root->left ?
	                             root->left : root->right;
	
	                if (temp == NULL) {
	                    delete root;
	                    return NULL;
	                }
	                else {
	                    Node* oldRoot = root;
	                    root = temp;
	                    delete oldRoot;
	                }
	            }
	
	            // Two children
	            else {
	                Node* temp = findMin(root->right);
	
	                root->data = temp->data;
	
	                root->right =
	                    deleteNode(root->right, temp->data);
	            }
	        }
	
	        if (root == NULL)
	            return root;
	
	        // Update height
	        root->height = 1 + max(getHeight(root->left),
	                               getHeight(root->right));
	
	        int balance = getBalance(root);
	
	        // LL
	        if (balance > 1 &&
	            getBalance(root->left) >= 0)
	            return rightRotate(root);
	
	        // LR
	        if (balance > 1 &&
	            getBalance(root->left) < 0) {
	            root->left = leftRotate(root->left);
	            return rightRotate(root);
	        }
	
	        // RR
	        if (balance < -1 &&
	            getBalance(root->right) <= 0)
	            return leftRotate(root);
	
	        // RL
	        if (balance < -1 &&
	            getBalance(root->right) > 0) {
	            root->right = rightRotate(root->right);
	            return leftRotate(root);
	        }
	
	        return root;
	    }
	
	    // Search
	    bool search(Node* root, int value) {
	        if (root == NULL)
	            return false;
	
	        if (root->data == value)
	            return true;
	
	        if (value < root->data)
	            return search(root->left, value);
	
	        return search(root->right, value);
	    }
	
	    // Inorder
	    void inorder(Node* root) {
	        if (root == NULL)
	            return;
	
	        inorder(root->left);
	        cout << root->data << " ";
	        inorder(root->right);
	    }
	
	    // Preorder
	    void preorder(Node* root) {
	        if (root == NULL)
	            return;
	
	        cout << root->data << " ";
	        preorder(root->left);
	        preorder(root->right);
	    }
	
	    // Postorder
	    void postorder(Node* root) {
	        if (root == NULL)
	            return;
	
	        postorder(root->left);
	        postorder(root->right);
	        cout << root->data << " ";
	    }
};

int main() {

    AVL tree;
    Node* root = NULL;

    root = tree.insert(root, 30);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 25);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);

    cout << "Inorder: ";
    tree.inorder(root);

    cout << "\nPreorder: ";
    tree.preorder(root);

    cout << "\nPostorder: ";
    tree.postorder(root);

    cout << "\n\nSearching 25: ";
    cout << (tree.search(root, 25) ? "Found" : "Not Found");

    root = tree.deleteNode(root, 20);

    cout << "\n\nAfter deleting 20: ";
    tree.inorder(root);

    return 0;
}

