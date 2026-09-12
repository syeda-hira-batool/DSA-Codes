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

    void insertEnd(int value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    bool search(int value) {

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == value) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
};

int main() {

    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    if (list.search(30)) {
        cout << "Value found";
    }
    else {
        cout << "Value not found";
    }

    return 0;
}
