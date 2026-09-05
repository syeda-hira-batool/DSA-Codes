#include<iostream>
using namespace std;

class Node {
	public:
	    int data;
	    Node* next;
	
	    Node(int value) {
	        data = value;
	        next = NULL;
	    }
};

int main(){
	
	Node* n1 = new Node(10);
	Node* n2 = new Node(20);
	Node* n3 = new Node(30);
	
	n1->next = n2;
	n2->next = n3;
	
	return 0;
	
}
