#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int value, int position) {

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {

    LinkedList list;

    list.insertAtPosition(10, 1);
    list.insertAtPosition(20, 2);
    list.insertAtPosition(30, 3);
    list.insertAtPosition(40, 4);

    // Insert 25 at position 3
    list.insertAtPosition(25, 3);

    list.display();

    return 0;
}
