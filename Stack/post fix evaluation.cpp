/*
    APPLICATION: Evaluate a Postfix expression, e.g. "23*54*+" = 26

    WHY A STACK?
    In postfix, every operator comes right after the two numbers it applies
    to. So we can scan left to right: numbers get pushed, and the moment we
    see an operator, the two most recent numbers (top of stack) are exactly
    the two it should be applied to.

    STEPS (scan left to right):
    - See a digit     -> push it onto the stack.
    - See an operator -> pop TWO values (b = top, a = next),
                          compute (a OPERATOR b),
                          push the result back onto the stack.
    - At the end, the single value left on the stack is the answer.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ---------- Custom Stack for storing integers ----------
class IntStack {
private:
    int data[100];
    int top;

public:
    IntStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int value = data[top];
        top--;
        return value;
    }
};

int evaluatePostfix(string postfix) {
    IntStack numbers;

    for (int i = 0; i < (int)postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            // single-digit number -> push it directly
            numbers.push(c - '0');
        } else {
            // operator -> pop the two most recent numbers
            int b = numbers.pop();  // popped first = right-hand operand
            int a = numbers.pop();  // popped second = left-hand operand

            switch (c) {
                case '+': numbers.push(a + b); break;
                case '-': numbers.push(a - b); break;
                case '*': numbers.push(a * b); break;
                case '/': numbers.push(a / b); break;
            }
        }
    }

    // whatever remains on the stack is the final answer
    return numbers.pop();
}

int main() {
    string postfix = "23*54*+";  // means (2*3) + (5*4) = 6 + 20 = 26

    cout << "Postfix: " << postfix << endl;
    cout << "Result:  " << evaluatePostfix(postfix) << endl;
    return 0;
}
