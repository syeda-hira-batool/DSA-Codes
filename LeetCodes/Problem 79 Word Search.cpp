#include <iostream>
#include <string>
using namespace std;

bool isSafe(char board[3][4], int x, int y, string p, int len) {
    if (x >= 0 && x < 3 && y >= 0 && y < 4 &&
        board[x][y] == p[len]) {
        return true;
    }
    else {
        return false;
    }
}

bool solveMaze(char board[3][4], string p, int x, int y, int len) {

    // Destination reached (entire word found)
    if (len == p.length()) {
        return true;
    }

    // Check boundaries and current character
    if (!isSafe(board, x, y, p, len)) {
        return false;
    }

    char temp = board[x][y];

    // Mark cell as visited
    board[x][y] = '#';

    // Move Down
    if (solveMaze(board, p, x + 1, y, len + 1))
        return true;

    // Move Right
    if (solveMaze(board, p, x, y + 1, len + 1))
        return true;

    // Move Up
    if (solveMaze(board, p, x - 1, y, len + 1))
        return true;

    // Move Left
    if (solveMaze(board, p, x, y - 1, len + 1))
        return true;

    // Backtracking
    board[x][y] = temp;
    return false;
}

int main() {
    char board[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string p;

    cout << "Enter the word you want to find: ";
    cin >> p;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (solveMaze(board, p, i, j, 0)) {
                cout << "Word found!";
                return 0;
            }
        }
    }

    cout << "Word not found.";
    return 0;
}

