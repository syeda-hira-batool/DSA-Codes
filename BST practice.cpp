#include<iostream>
using namespace std; 

int n = 5;
int arr[5] = {9,2,1,88,3};
	
class Node{
	public:
		Node* left;
		Node* right;
		int data;
		
		Node(int d){
			data = d;
			left = right = NULL;
		}
};

Node* insert(Node* root, int val){
	if(root == NULL){
		return new Node(val);
	}

	if(val < root->data){
		root->left = insert(root->left, val);
	}
	else{
		root->right = insert(root->right, val);	
	}
	return root;

}

Node* buildBST(int arr[], int n){
	Node* root = NULL;
	for(int i=0; i<n; i++){
		root = insert(root , arr[i]);
	}
	return root;
}

Node* inOrder(Node* root){  //sorted version
	if(root == NULL){
		return root;
	}
	root->left = inOrder(root->left);
	cout << root->data << " " ;
	root->right = inOrder(root->right);
}

Node* preOrder(Node* root){
	if(root == NULL){
		return root;
	}
	cout << root->data << " " ;
	root->left = preOrder(root->left);
	root->right = preOrder(root->right);
}

Node* postOrder(Node* root){
	if(root == NULL){
		return root;
	}
	root->left = postOrder(root->left);
	root->right = postOrder(root->right);
	cout << root->data << " " ;
}

bool searchInBST(Node* root, int key){
	if(root == NULL){
		return false;
	}
	if(root->data == key){
		return true;
	}
	if(key < root->data){
		return searchInBST(root->left, key);
	}
	else{
		return searchInBST(root->right, key);
	}

}

Node* succcessor(Node* root){
	while(root!= NULL && root->left != NULL){
		root = root->left;
	} 
	return root;
}

Node* precesdor(Node* root){
    while(root != NULL && root->right != NULL){
        root = root->right;
    } 
    return root;
}

Node* minimum(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* maximum(Node* root){
    while(root != NULL && root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
	if(root == NULL){
		return NULL;
	}
	if(key < root->data){
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->data){
		root->right = deleteNode(root->right, key);
	}
	else{
		//key = root
		if(root->left == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else{ //2 childern  
			Node* IS = succcessor(root->right);
			root->data = IS->data;
			root->right = deleteNode(root->right, IS->data);
		}
	}
	
	return root;
}

int main(){
	
	Node* root;
	root = buildBST(arr, n);
	inOrder(root);
	cout << endl;
	cout <<  searchInBST(root, 88);
	root = deleteNode(root, 9);
	cout << endl;
	inOrder(root);
	
	
}
