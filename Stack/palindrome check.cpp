/*
    APPLICATION: Check if a word/string is a palindrome, e.g. "madam"

    WHY A STACK?
    A stack reverses whatever order you push things in (LIFO). So if we
    push every character of the string, then pop them all back out, we get
    the REVERSED string. If the reversed string equals the original, it's
    a palindrome.
*/

#include <iostream>
#include <string>
using namespace std;

// ---------- Custom Stack for storing characters ----------
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
        char value = data[top];
        top--;
        return value;
    }
};

bool isPalindrome(string word) {
    CharStack letters;

    // Step 1: push every character, left to right
    for (int i = 0; i < (int)word.length(); i++) {
        letters.push(word[i]);
    }

    // Step 2: pop every character -- this naturally reverses the order
    string reversedWord = "";
    for (int i = 0; i < (int)word.length(); i++) {
        reversedWord += letters.pop();
    }

    // Step 3: palindrome only if original == reversed
    return word == reversedWord;
}

int main() {
    string word1 = "madam";
    string word2 = "hello";

    cout << word1 << " -> " << (isPalindrome(word1) ? "Palindrome" : "Not Palindrome") << endl;
    cout << word2 << " -> " << (isPalindrome(word2) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
