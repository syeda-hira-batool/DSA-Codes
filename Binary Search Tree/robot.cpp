//similar to rat in a maze problem
#include <iostream>
using namespace std;

void display(int** visitedMaze, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << visitedMaze[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int** maze, int** visitedMaze, int N, int x, int y) {

    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visitedMaze[x][y] == 0) {
        return true;
    }
    else {
        return false;
    }
}

void solveMaze(int** maze, int** visitedMaze, int N, int x, int y, int& pathCount) {

    if (!isSafe(maze, visitedMaze, N, x, y)) {
        return;
    }

    visitedMaze[x][y] = 1;

    if (x == N - 1 && y == N - 1) {   //our destination
        pathCount++;

        cout << "\nSolution " << pathCount << ":" << endl;
        display(visitedMaze, N);

        visitedMaze[x][y] = 0;  //backtracking logic
        return;
    }

    solveMaze(maze, visitedMaze, N, x + 1, y, pathCount);
    solveMaze(maze, visitedMaze, N, x, y + 1, pathCount);
    solveMaze(maze, visitedMaze, N, x - 1, y, pathCount);
    solveMaze(maze, visitedMaze, N, x, y - 1, pathCount);

    visitedMaze[x][y] = 0;  //backtracking logic
}

int main() {

    int N;
    cout << "Enter the size of the maze: ";
    cin >> N;

    int** maze = new int*[N];
    int** visitedMaze = new int*[N];

    for (int i = 0; i < N; i++) {
        maze[i] = new int[N];
        visitedMaze[i] = new int[N];
    }

    cout << "Enter the maze:" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];

            if (maze[i][j] != 0 && maze[i][j] != 1) {
                cout << "Enter only 0 or 1." << endl;

                for (int k = 0; k < N; k++) {
                    delete[] maze[k];
                    delete[] visitedMaze[k];
                }

                delete[] maze;
                delete[] visitedMaze;
                return 0;
            }

            visitedMaze[i][j] = 0;
        }
    }

    cout << "\noriginal maze:" << endl;
    display(maze, N);

    int pathCount = 0;

    if (maze[0][0] == 0 || maze[N - 1][N - 1] == 0) { //start and des open or not
        cout << "\nNo valid path exists." << endl;
    }
    else {
        solveMaze(maze, visitedMaze, N, 0, 0, pathCount);

        if (pathCount == 0) {
            cout << "\nNo valid path exists." << endl;
        }
        else {
            cout << "\nTotal valid paths: " << pathCount << endl;
        }
    }

    for (int i = 0; i < N; i++) {
        delete[] maze[i];
        delete[] visitedMaze[i];
    }

    delete[] maze;
    delete[] visitedMaze;

    return 0;
}
