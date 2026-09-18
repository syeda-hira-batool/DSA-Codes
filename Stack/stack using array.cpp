#include <iostream>
#include <string>
using namespace std;

class Stack {
  private:
    int top;
    int arr[5];

  public:
    Stack() {
      top = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }

  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == 4)
      return true;
    else
      return false;
  }

  void push(int val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      top++;
      arr[top] = val;
    }
  }

  int pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }

  int count() {
    return (top + 1);
  }

  int peek(int pos) {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      return arr[pos];
    }
  }

  void change(int pos, int val) {
    arr[pos] = val;
    cout << "value changed at location " << pos << endl;
  }

  void display() {
    cout << "All values in the Stack are " << endl;
    for (int i = 4; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }
};

int main() {
  Stack s1;

  // isEmpty() / isFull() on a fresh stack
  cout << "Is Empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;
  cout << "Is Full? " << (s1.isFull() ? "Yes" : "No") << endl;

  // push()
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50); // stack now full
  s1.push(60); // triggers overflow message

  // isFull() after filling
  cout << "Is Full? " << (s1.isFull() ? "Yes" : "No") << endl;

  // count()
  cout << "Count: " << s1.count() << endl;

  // peek()
  cout << "Peek at position 2: " << s1.peek(2) << endl;

  // change()
  s1.change(1, 99);

  // display() after changes
  s1.display();

  // pop()
  cout << "Popped: " << s1.pop() << endl;
  cout << "Count after pop: " << s1.count() << endl;

  // display() after pop
  s1.display();

  return 0;
}
