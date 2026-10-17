#include <iostream>
using namespace std;

bool isSafe(int** board, int n, int row, int col) {

    for (int i = 0; i < row; i++) { //checking same col in prev rows
        if (board[i][col] == 1){
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) { //checking upper left diagonal
        if (board[i][j] == 1){
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {//checking upper right diagonal
        if (board[i][j] == 1){
            return false;
        }
    }
    
	return true;
}

bool solveNQueens(int** board, int n, int row) {

    if (row == n){
        return true; //base case: all queens have been placed!
    }

    for (int col = 0; col < n; col++) { //trying every col in each row

        if (isSafe(board, n, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, n, row + 1)){
                return true;
            }

            board[row][col] = 0; //main backtracking logic
        }
    }

    return false;
}

int main() {

    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid!";
        return 0;
    }

    int** board = new int*[n];

    for (int i = 0; i < n; i++) {
        board[i] = new int[n]();
    }

    if (solveNQueens(board, n, 0)) {
        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << "X ";
                }
            }
            cout << endl;
        }
    }

    else {
        cout << "No solutions";
    }

    for (int i = 0; i < n; i++) { //free the memory
        delete[] board[i];
    }
    delete[] board;

    return 0;
}

