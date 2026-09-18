#include <iostream>
using namespace std;

class Node {
  public:
    int key;
    int data;
    Node* next;

    Node() {
      key = 0;
      data = 0;
      next = NULL;
    }
    Node(int k, int d) {
      key = k;
      data = d;
      next = NULL;
    }
};

class Stack {
  public:
    Node* top;

    Stack() {
      top = NULL;
    }

    bool isEmpty() {
      if (top == NULL)
        return true;
      else
        return false;
    }

    bool checkIfNodeExist(Node* n) {
      Node* temp = top;
      bool exist = false;
      while (temp != NULL) {
        if (temp->key == n->key) {
          exist = true;
          break;
        }
        temp = temp->next;
      }
      return exist;
    }

    void push(Node* n) {
      if (top == NULL) {
        top = n;
        cout << "Node PUSHED successfully" << endl;
      } else if (checkIfNodeExist(n)) {
        cout << "Node already exists with this Key value. "
             << "Enter a different Key value" << endl;
      } else {
        Node* temp = top;
        top = n;
        n->next = temp;
        cout << "Node PUSHED successfully" << endl;
      }
    }

    Node* pop() {
      Node* temp = NULL;
      if (isEmpty()) {
        cout << "stack underflow" << endl;
        return temp;
      } else {
        temp = top;
        top = top->next;
        return temp;
      }
    }

    Node* peek() {
      if (isEmpty()) {
        cout << "stack underflow" << endl;
        return NULL;
      } else {
        return top;
      }
    }

    int count() {
      int count = 0;
      Node* temp = top;
      while (temp != NULL) {
        count++;
        temp = temp->next;
      }
      return count;
    }

    void display() {
      cout << "All values in the Stack are:" << endl;
      Node* temp = top;
      while (temp != NULL) {
        cout << "[" << temp->key << "," << temp->data << "] -> " << endl;
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  Stack s1;

  // isEmpty() on a fresh stack
  cout << "Is Empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;

  // push() — each node is heap-allocated, then linked in as new top
  s1.push(new Node(1, 100));
  s1.push(new Node(2, 200));
  s1.push(new Node(3, 300));

  // push() with a duplicate key — checkIfNodeExist() blocks it
  s1.push(new Node(2, 999));

  // count()
  cout << "Count: " << s1.count() << endl;

  // display()
  s1.display();

  // peek() — read the top node without removing it
  Node* topNode = s1.peek();
  if (topNode != NULL)
    cout << "Peek: [" << topNode->key << "," << topNode->data << "]" << endl;

  // pop() — remove and return the top node
  Node* popped = s1.pop();
  if (popped != NULL) {
    cout << "Popped: [" << popped->key << "," << popped->data << "]" << endl;
    delete popped; // free the node once we're done with it
  }

  // count() and display() after pop
  cout << "Count after pop: " << s1.count() << endl;
  s1.display();

  return 0;
}
