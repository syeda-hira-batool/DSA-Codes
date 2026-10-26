#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int v){
            val = v;
            left = NULL;
            right = NULL;
        }
};

class BST{
    private:
        Node* root;

        Node* insert(Node* root, int key){
            if(root == NULL){
                return new Node(key);
            }

            if(key < root->val){
                root->left = insert(root->left, key);
            }
            else if(key > root->val){
                root->right = insert(root->right, key);
            }

            return root;
        }

        Node* search(Node* root, int key){
            if(root == NULL || root->val == key){
                return root;
            }

            if(key < root->val){
                return search(root->left, key);
            }
            else{
                return search(root->right, key);
            }
        }
        
        Node* minimum(Node* root){
            if(root == NULL){
                return NULL;
            }

            while(root->left != NULL){
                root = root->left;
            }

            return root;
        }

        
        Node* maximum(Node* root){
            if(root == NULL){
                return NULL;
            }

            while(root->right != NULL){
                root = root->right;
            }

            return root;
        }

        Node* deleteNode(Node* root, int key){
            if(root == NULL){
                return NULL;
            }

            if(key < root->val){
                root->left = deleteNode(root->left, key);
            }
            else if(key > root->val){
                root->right = deleteNode(root->right, key);
            }
            else{
                // case 1: no left child
                if(root->left == NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }

                // case 2: no right child
                else if(root->right == NULL){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                // case 3: 2 children
                Node* temp = minimum(root->right);

                root->val = temp->val;

                root->right = deleteNode(root->right, temp->val);
            }

            return root;
        }

        int height(Node* root){
            if(root == NULL){
                return 0;
            }

            int left = height(root->left);
            int right = height(root->right);

            if(left > right){
                return left + 1;
            }
            else{
                return right + 1;
            }
        }

        void inOrder(Node* root){
            if(root == NULL){
                return;
            }

            inOrder(root->left);
            cout << root->val << " ";
            inOrder(root->right);
        }

    public:
        BST(){
            root = NULL;
        }

        void insert(int key){
            root = insert(root, key);
        }

        bool search(int key){
            return search(root, key) != NULL;
        }

        void deleteKey(int key){
            root = deleteNode(root, key);
        }

        Node* findMin(){
            return minimum(root);
        }

        Node* findMax(){
            return maximum(root);
        }

        int height(){
            return height(root);
        }

        Node* inorderSuccessor(int key){
            Node* curr = root;
            Node* successor = NULL;

            while(curr != NULL){
                if(key < curr->val){
                    successor = curr;
                    curr = curr->left;
                }
                else if(key > curr->val){
                    curr = curr->right;
                }
                else{
                	
                    if(curr->right != NULL){
                        return minimum(curr->right);
                    }

                    return successor;
                }
            }

            return NULL;
        }

        void display(){
            inOrder(root);
            cout << endl;
        }
};

int main(){
    BST tree;

    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = 6;

    for(int i = 0; i < n; i++){
        tree.insert(arr[i]);
    }

    cout << "Inorder traversal: ";
    tree.display();

    int key = 30;

    if(tree.search(key)){
        cout << key << " found in BST" << endl;
    }
    else{
        cout << key << " not found in BST" << endl;
    }

    Node* mn = tree.findMin();

    if(mn != NULL){
        cout << "Minimum: " << mn->val << endl;
    }
    else{
        cout << "Tree is empty" << endl;
    }

    Node* mx = tree.findMax();

    if(mx != NULL){
        cout << "Maximum: " << mx->val << endl;
    }
    else{
        cout << "Tree is empty" << endl;
    }

    cout << "Height: " << tree.height() << endl;

    Node* succ = tree.inorderSuccessor(30);

    if(succ != NULL){
        cout << "Successor of 30: " << succ->val << endl;
    }
    else{
        cout << "No inorder successor exists" << endl;
    }

    tree.deleteKey(30);

    cout << "After deleting 30: ";
    tree.display();

    return 0;
}

