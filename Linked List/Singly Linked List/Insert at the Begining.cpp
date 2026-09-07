#include <iostream>
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

class LinkedList {
	public:
	    Node* head;
	
	    LinkedList() {
	        head = NULL;
	    }
	
	    void insertBeginning(int value) {
	        Node* newNode = new Node(value);
	
	        newNode->next = head;
	        head = newNode;
	    }
	
	    void display() {
	        Node* temp = head;
	
	        while (temp != NULL) {
	            cout << temp->data << " ";
	            temp = temp->next;
	        }
	    }
};

int main() {

    LinkedList list;

    list.insertBeginning(30);
    list.insertBeginning(20);
    list.insertBeginning(10);

    list.display();

    return 0;
}
