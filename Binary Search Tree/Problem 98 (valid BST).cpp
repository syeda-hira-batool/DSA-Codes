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

bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* root, long long min, long long max) {
        if (root == NULL) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return isValid(root->left, min, root->val) &&
               isValid(root->right, root->val, max);
    }

int main(){
	
	
}
