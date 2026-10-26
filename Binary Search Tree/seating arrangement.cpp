//similar to N queens problem
#include <iostream>
#include <cmath> //for absolute value in diagnol
using namespace std;

const int rows = 6;
const int cols = 8;
const int numCourse = 4;

const char courcesChar[numCourse] = {'P', 'D', 'O', 'C'};
// P for Programming
// D for Database Systems
// O for Operating Systems
// C for Computer Networks

const int maxArrangements = 10;

void display(char** grid) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int courseIdx, int r, int c, int courseRows[], int courseCols[]) {

    if (r == 3 && c == 3) {
        return false;  //(3,3) already restricted - broken
    }

    if (courseIdx == 0 && r != 0) {
        return false;
    }

    for (int prev = 0; prev < courseIdx; prev++) {
        int prevR = courseRows[prev];
        int prevC = courseCols[prev];

        if (prevR == r) { //same row
            return false;
        }

        if (prevC == c) {  //same col
            return false;
        }

        if (abs(prevR - r) == abs(prevC - c)) {  //diagonal
            return false;
        }
    }

    return true;
}

void solveSeating(char** grid, int courseIdx, int courseRows[], int courseCols[], int& arrangementCount) {

    if (arrangementCount >= maxArrangements) {
        return;
    }

    if (courseIdx == numCourse) {
        arrangementCount++;

        cout << "Arrangement " << arrangementCount << ":" << endl;
        for (int i = 0; i < numCourse; i++) {
            cout << " (" << courcesChar[i] << "): (" << courseRows[i] << ", " << courseCols[i] << ")" << endl;
        }
        cout << "Seating Layout:" << endl;
        display(grid);
        return;
    }

    int startRow, endRow;

    if (courseIdx == 0) {
        startRow = 0;
        endRow = 0;
    }
    else {
        startRow = 1;
        endRow = rows - 1;
    }

    for (int r = startRow; r <= endRow; r++) {
        for (int c = 0; c < cols; c++) {

            if (arrangementCount >= maxArrangements) {
                return;
            }

            if (isSafe(courseIdx, r, c, courseRows, courseCols)) {

                grid[r][c] = courcesChar[courseIdx];
                courseRows[courseIdx] = r;
                courseCols[courseIdx] = c;

                solveSeating(grid, courseIdx + 1, courseRows, courseCols, arrangementCount);
                grid[r][c] = '.';  //undo through backtracking
                courseRows[courseIdx] = -1;
                courseCols[courseIdx] = -1;
            }
        }
    }
}

int main() {

    char** grid = new char*[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            grid[i][j] = '.'; //unassigned
        }
    }

    int courseRows[numCourse] = {-1, -1, -1, -1};
    int courseCols[numCourse] = {-1, -1, -1, -1};

    int arrangementCount = 0;

    solveSeating(grid, 0, courseRows, courseCols, arrangementCount);

    if (arrangementCount == 0) {
        cout << "\nNo valid seating arrangement exists." << endl;
    }
    else {
        cout << "\nDisplayed arrangements: " << arrangementCount << endl;
        if (arrangementCount == maxArrangements) {
            cout << "Stopped after displaying the first " << maxArrangements << " arrangements." << endl;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}

