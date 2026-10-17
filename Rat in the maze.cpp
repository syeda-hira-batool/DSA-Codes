#include <iostream>
using namespace std;

int const N = 4;

void display(int visitedMaze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << visitedMaze[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y) {
	
	if(x>= 0 && x<N && y>=0 && y<N && maze[x][y]){
		return true;
	}
	else{
		return false;
	}
}

bool solveMaze(int maze[N][N], int visitedMaze[N][N], int x, int y) {
	
    if (x == N - 1 && y == N - 1) {   //our destination
        visitedMaze[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        visitedMaze[x][y] = 1;

        if (solveMaze(maze, visitedMaze, x + 1, y)){
        	return true; //moving down
		}

        // Move Right
        if (solveMaze(maze, visitedMaze, x, y + 1)){
        	return true; //moving right
		}

        if (solveMaze(maze, visitedMaze, x - 1, y)){
        	return true; //moving up
		}

        if (solveMaze(maze, visitedMaze, x, y - 1)){
        	return true; //moving left
		}

        visitedMaze[x][y] = 0;  //backtracking logic!
        return false;
    }

    return false;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int visitedMaze[N][N] = {0};
    cout << "Our original maze: " << endl;
    display(maze);
    cout << endl;

    if (solveMaze(maze, visitedMaze, 0, 0)) {
        cout << "Solution: " << endl;
        display(visitedMaze);
    }
    else {
        cout << "No solution exists.";
    }

    return 0;
}
