/*
    APPLICATION: Check if brackets in an expression are balanced
    e.g. "{[A+(B*C)]-D}"  -> Balanced
         "{[A+(B*C)]-D}}" -> Not Balanced (extra closing bracket)

    WHY A STACK?
    Every closing bracket must match the MOST RECENTLY opened bracket
    that hasn't been closed yet -- that's exactly LIFO behaviour.

    STEPS (scan left to right):
    - See an opening bracket ( { [  -> push it.
    - See a closing bracket  ) } ]  -> pop the top and check it matches.
      If the stack is empty, or the popped bracket doesn't match -> NOT balanced.
    - At the end, if the stack is empty -> balanced.
                  if anything is left  -> NOT balanced (unclosed brackets).
*/

#include <iostream>
#include <string>
using namespace std;

// ---------- Custom Stack for storing characters (brackets) ----------
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

    char peek() {
        if (isEmpty()) return '\0';
        return data[top];
    }
};

// checks if a closing bracket correctly matches its opening bracket
bool isMatchingPair(char openBracket, char closeBracket) {
    return (openBracket == '(' && closeBracket == ')') ||
           (openBracket == '{' && closeBracket == '}') ||
           (openBracket == '[' && closeBracket == ']');
}

bool isBalanced(string expression) {
    CharStack brackets;

    for (int i = 0; i < (int)expression.length(); i++) {
        char c = expression[i];

        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            // closing bracket with nothing to match -> unbalanced
            if (brackets.isEmpty()) {
                return false;
            }
            char openBracket = brackets.pop();
            if (!isMatchingPair(openBracket, c)) {
                return false; // wrong TYPE of bracket, e.g. "(]"
            }
        }
        // any other character (letters, operators) is simply ignored
    }

    // balanced only if every opening bracket found its closing partner
    return brackets.isEmpty();
}

int main() {
    string expr1 = "{[A+(B*C)]-D}";
    string expr2 = "{[A+(B*C)]-D}}"; // extra closing brace -> unbalanced

    cout << expr1 << " -> " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
