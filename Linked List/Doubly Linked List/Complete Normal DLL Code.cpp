#include <iostream>
using namespace std;

class Node{
	public:
	    int data;
	    Node* prev;
	    Node* next;	
	
	    Node(int value){
	        data = value;
	        prev = NULL;
	        next = NULL;
	    }
};


class DoublyLinkedList{
	private:
	
	    Node* head;
	    Node* tail;
	
	public:
	
	    DoublyLinkedList(){
	        head = NULL;
	        tail = NULL;
	    }
	
	    // Insert in empty list
	    void insertEmpty(int value){
	        Node* newNode = new Node(value);
	
	        head = newNode;
	        tail = newNode;
	    }
	
	    // Insert at front
	    void insertFront(int value){
	        Node* newNode = new Node(value);
	
	        if(head == NULL)
	        {
	            head = newNode;
	            tail = newNode;
	            return;
	        }
	
	        newNode->next = head;
	        head->prev = newNode;
	
	        head = newNode;
	    }
	
	    // Insert at end
	    void insertEnd(int value){
	        Node* newNode = new Node(value);
	
	        if(head == NULL)
	        {
	            head = newNode;
	            tail = newNode;
	            return;
	        }
	
	        tail->next = newNode;
	        newNode->prev = tail;
	
	        tail = newNode;
	    }
	
	    // Insert at any position
	    void insertAtPosition(int value, int position){
	        if(position == 1)
	        {
	            insertFront(value);
	            return;
	        }
	
	        if(head == NULL)
	            return;
	
	        Node* temp = head;
	
	        for(int i = 1; i < position - 1; i++)
	        {
	            if(temp->next == NULL)
	                return;
	
	            temp = temp->next;
	        }
	
	        Node* newNode = new Node(value);
	
	        newNode->prev = temp;
	        newNode->next = temp->next;
	
	        if(temp->next != NULL)
	            temp->next->prev = newNode;
	
	        temp->next = newNode;
	
	        if(newNode->next == NULL)
	            tail = newNode;
	    }
	
	    // Search
	    bool search(int value){
	        Node* temp = head;
	
	        while(temp != NULL)
	        {
	            if(temp->data == value)
	                return true;
	
	            temp = temp->next;
	        }
	
	        return false;
	    }
	
	    // Display
	    void display(){
	        Node* temp = head;
	
	        while(temp != NULL)
	        {
	            cout << temp->data << " ";
	            temp = temp->next;
	        }
	
	        cout << endl;
	    }
	
	    // Delete front
	    void deleteFront(){
	        if(head == NULL)
	            return;
	
	        Node* temp = head;
	
	        head = head->next;
	
	        if(head != NULL)
	            head->prev = NULL;
	        else
	            tail = NULL;
	
	        delete temp;
	    }
	
	    // Delete at position
	    void deleteAtPosition(int position){
	        if(head == NULL)
	            return;
	
	        if(position == 1)
	        {
	            deleteFront();
	            return;
	        }
	
	        Node* temp = head;
	
	        for(int i = 1; i < position; i++)
	        {
	            if(temp == NULL)
	                return;
	
	            temp = temp->next;
	        }
	
	        if(temp == NULL)
	            return;
	
	        if(temp == tail)
	        {
	            deleteEnd();
	            return;
	        }
	
	        temp->prev->next = temp->next;
	        temp->next->prev = temp->prev;
	
	        delete temp;
	    }
	
	    // Delete end
	    void deleteEnd(){
	        if(head == NULL)
	            return;
	
	        if(head == tail)
	        {
	            delete head;
	
	            head = NULL;
	            tail = NULL;
	
	            return;
	        }
	
	        Node* temp = tail;
	
	        tail = tail->prev;
	
	        tail->next = NULL;
	
	        delete temp;
	    }
	
	    ~DoublyLinkedList(){
	        Node* temp = head;
	
	        while(temp != NULL)
	        {
	            Node* next = temp->next;
	
	            delete temp;
	
	            temp = next;
	        }
	
	        head = NULL;
	        tail = NULL;
	    }
};
