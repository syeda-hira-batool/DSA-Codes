/*
    APPLICATION: Undo / Redo feature (like in a text editor), using two stacks

    WHY TWO STACKS?
    - undoStack: remembers every PREVIOUS version of the text, most recent on top.
    - redoStack: remembers versions we've undone, in case the user wants them back.

    RULES:
    - Typing something new:
          save the CURRENT text onto undoStack (so we can undo back to it),
          then clear redoStack (a fresh edit invalidates old "redo" history).
    - Undo:
          save current text onto redoStack, then restore the top of undoStack.
    - Redo:
          save current text onto undoStack, then restore the top of redoStack.
*/

#include <iostream>
#include <string>
using namespace std;

// ---------- Custom Stack for storing strings (text snapshots) ----------
class StringStack {
private:
    string data[100];
    int top;

public:
    StringStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(string value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    string pop() {
        if (isEmpty()) return "";
        string value = data[top];
        top--;
        return value;
    }

    // wipes the stack -- used when a new edit makes "redo" history invalid
    void clear() {
        top = -1;
    }
};

class TextEditor {
private:
    string currentText;
    StringStack undoStack;
    StringStack redoStack;

public:
    void type(string newText) {
        undoStack.push(currentText); // remember what the text looked like BEFORE this change
        redoStack.clear();           // a new edit means old redo history no longer makes sense
        currentText += newText;
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo" << endl;
            return;
        }
        redoStack.push(currentText);   // save current state so redo can bring it back
        currentText = undoStack.pop(); // go back to the previous state
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo" << endl;
            return;
        }
        undoStack.push(currentText);   // save current state so undo can come back here
        currentText = redoStack.pop(); // re-apply the undone state
    }

    void show() {
        cout << "Text: \"" << currentText << "\"" << endl;
    }
};

int main() {
    TextEditor editor;

    editor.type("Hello");
    editor.type(" World");
    editor.show();      // "Hello World"

    editor.undo();
    editor.show();      // "Hello"

    editor.undo();
    editor.show();      // "" (empty, back to the very start)

    editor.redo();
    editor.show();      // "Hello" (redo brought it back)

    return 0;
}
