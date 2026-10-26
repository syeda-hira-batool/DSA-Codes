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

Node* helper(int arr[], int start, int end ){
	
	if(start > end){
		return NULL;
	}
	
	int mid = start + (end-start)/2;
	Node* root = new Node(arr[mid]);
	root->left = helper(arr, start, mid-1);
	root->right = helper(arr, mid+1, end);
	
	return root;
}

Node* sortedArrayToBST(int arr[]){
	return helper(arr, arr.size()-1);
}

int main(){
	
	
}
