/*
    APPLICATION: Adding two large numbers using a stack

    WHY A STACK?
    Numbers are stored as strings like "9875". The units digit is at the
    END of the string, but addition needs to start from the units digit.
    A stack naturally reverses order (LIFO), so if we push digits left to
    right, popping gives us units digit first -- exactly what we need.

    STEPS:
    1. Push every digit of num1 onto stack1, and every digit of num2 onto stack2.
    2. Pop one digit from each stack at a time (this processes units, then
       tens, then hundreds... automatically) and add them + carry.
    3. Push each result digit onto a third stack.
    4. Pop the result stack to build the final answer string (this reverses
       it back into the correct left-to-right order).
*/

#include <iostream>
#include <string>
using namespace std;

// ---------- Custom Stack for storing integers (digits) ----------
class IntStack {
private:
    int data[200];   // fixed-size array to hold stack elements
    int top;         // index of the topmost element (-1 means empty)

public:
    IntStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 199;
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

// ---------- Main addition logic ----------
string addLargeNumbers(string num1, string num2) {
    IntStack stack1, stack2, resultStack;

    // Step 1: push every digit of each number onto its own stack
    for (int i = 0; i < (int)num1.length(); i++) {
        stack1.push(num1[i] - '0');   // '9' - '0' = 9 (converts char to int)
    }
    for (int i = 0; i < (int)num2.length(); i++) {
        stack2.push(num2[i] - '0');
    }

    int remaining1 = num1.length();  // how many digits are still left in stack1
    int remaining2 = num2.length();  // how many digits are still left in stack2
    int carry = 0;
    int totalResultDigits = 0;

    // Step 2 & 3: add digit by digit (units first), just like addition on paper
    while (remaining1 > 0 || remaining2 > 0 || carry != 0) {
        int columnSum = carry;

        if (remaining1 > 0) {
            columnSum += stack1.pop();
            remaining1--;
        }
        if (remaining2 > 0) {
            columnSum += stack2.pop();
            remaining2--;
        }

        resultStack.push(columnSum % 10);  // keep only the ones digit
        carry = columnSum / 10;            // carry the tens digit forward
        totalResultDigits++;
    }

    // Step 4: pop the result stack to build the answer in correct order
    string answer = "";
    for (int i = 0; i < totalResultDigits; i++) {
        answer += to_string(resultStack.pop());
    }
    return answer;
}

int main() {
    string a = "9875";
    string b = "679";

    cout << a << " + " << b << " = " << addLargeNumbers(a, b) << endl;
    return 0;
}
