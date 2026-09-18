/*
    APPLICATION: Convert Infix expression (A+B) to Postfix (AB+)

    WHY A STACK?
    In postfix, operators come AFTER their operands. To reorder operators
    correctly (respecting precedence and brackets), we temporarily "hold"
    operators on a stack until we know where they belong in the output.

    RULES (scan the infix expression left to right):
    - Operand (letter/digit)  -> write directly to output.
    - '('                     -> push onto stack (marks a new sub-expression).
    - ')'                     -> pop and output operators until '(' is found,
                                  then discard the '('.
    - Operator (+ - * / ^)    -> pop and output any operators on the stack
                                  that have GREATER OR EQUAL precedence,
                                  then push the current operator.
    - End of expression       -> pop and output everything left on the stack.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ---------- Custom Stack for storing characters (operators) ----------
class CharStack {
private:
    char data[100];
    int top;

public:
    CharStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    char pop() {
        if (isEmpty()) return '\0';
        char value = data[top];
        top--;
        return value;
    }

    // look at the top element WITHOUT removing it
    char peek() {
        if (isEmpty()) return '\0';
        return data[top];
    }
};

// higher number = higher precedence (done first)
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    CharStack operatorStack;
    string postfix = "";

    for (int i = 0; i < (int)infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            // Rule: operand goes straight to the output
            postfix += c;
        }
        else if (c == '(') {
            // Rule: opening bracket always goes on the stack
            operatorStack.push(c);
        }
        else if (c == ')') {
            // Rule: unwind the stack until we hit the matching '('
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix += operatorStack.pop();
            }
            operatorStack.pop(); // remove the '(' itself (not added to output)
        }
        else {
            // Rule: it's an operator (+, -, *, /, ^)
            // Pop out any operators that should be applied BEFORE this one
            while (!operatorStack.isEmpty() &&
                   precedence(operatorStack.peek()) >= precedence(c)) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Anything left on the stack goes to the output at the end
    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+B*(C-D)/E";

    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
