/*
    APPLICATION: Tower of Hanoi, solved WITHOUT recursion using an explicit stack

    BACKGROUND:
    Tower of Hanoi is normally solved with recursion:
        hanoi(n, from, aux, to):
            if n == 0: return
            hanoi(n-1, from, to, aux)      // step A: move smaller disks out of the way
            print "move disk n from -> to" // step B: move the big disk
            hanoi(n-1, aux, from, to)      // step C: move smaller disks onto the big one

    Recursion secretly uses the COMPUTER'S CALL STACK to remember what to do
    next. This program makes that hidden stack visible and explicit.

    HOW IT WORKS:
    Each "Move" pushed onto our stack is a TASK, not necessarily a disk move.
    - stage 0 = "this is a sub-problem, expand it into 3 smaller tasks"
    - stage 1 = "this is a real move, just print it"

    Because a stack is LIFO, we push the 3 sub-tasks in REVERSE order
    (C, B, A) so that when we pop them, they come out in the correct
    order (A, B, C).
*/

#include <iostream>
using namespace std;

struct Move {
    int n;              // how many disks this task involves
    char from, aux, to; // rod names
    int stage;          // 0 = needs to be expanded, 1 = ready to print
};

// ---------- Custom Stack for storing Move tasks ----------
class MoveStack {
private:
    Move data[200];
    int top;

public:
    MoveStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 199;
    }

    void push(Move task) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        data[top] = task;
    }

    Move pop() {
        Move task = data[top];
        top--;
        return task;
    }
};

void towerOfHanoiIterative(int n, char from, char aux, char to) {
    MoveStack tasks;

    // start with one big task: "solve for n disks"
    Move firstTask = {n, from, aux, to, 0};
    tasks.push(firstTask);

    while (!tasks.isEmpty()) {
        Move current = tasks.pop();

        if (current.n == 0) {
            continue; // nothing to do for 0 disks
        }

        if (current.stage == 0) {
            // This is a sub-problem -> break it into 3 smaller tasks.
            // Pushed in REVERSE order so they get executed in the right order:
            //   1st executed: move (n-1) disks from -> aux
            //   2nd executed: print the move of disk n
            //   3rd executed: move (n-1) disks aux -> to
            Move step3 = {current.n - 1, current.aux, current.from, current.to, 0};
            Move step2 = {current.n, current.from, current.aux, current.to, 1};
            Move step1 = {current.n - 1, current.from, current.to, current.aux, 0};

            tasks.push(step3);
            tasks.push(step2);
            tasks.push(step1);
        } else {
            // stage 1 -> this task is a real move, just print it
            cout << "Move disk " << current.n
                 << " from " << current.from
                 << " to "   << current.to << endl;
        }
    }
}

int main() {
    int numberOfDisks = 3;

    cout << "Tower of Hanoi for " << numberOfDisks << " disks:" << endl;
    towerOfHanoiIterative(numberOfDisks, 'A', 'B', 'C');
    return 0;
}
