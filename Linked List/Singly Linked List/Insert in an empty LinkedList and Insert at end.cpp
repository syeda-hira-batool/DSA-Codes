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
	
	    // Insert into empty list
	    void insertEmpty(int value) {
	        Node* newNode = new Node(value);
	        head = newNode;
	    }
	
	    // Insert at end
	    void insertEnd(int value) {
	
	        Node* newNode = new Node(value);
	
	        // If list is empty
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	
	        // Find last node
	        Node* temp = head;
	
	        while (temp->next != NULL) {
	            temp = temp->next;
	        }
	
	        // Connect last node to new node
	        temp->next = newNode;
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

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    list.display();

    return 0;
}
