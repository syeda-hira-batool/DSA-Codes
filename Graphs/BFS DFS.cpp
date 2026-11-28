#include <iostream>
using namespace std;

const int MAX = 100;

int adj[MAX][MAX];
bool visited[MAX];
int vertices;

// DFS
void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = true;

    for (int i = 0; i < vertices; i++)
    {
        if (adj[vertex][i] == 1 && !visited[i])
            DFS(i);
    }
}

// BFS
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear)
    {
        int vertex = queue[front++];
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    vertices = 6;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;

    // Add edges (Undirected connected graph)
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[2][5] = adj[5][2] = 1;
    adj[4][5] = adj[5][4] = 1;

    cout << "DFS: ";
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    DFS(0);

    cout << "\nBFS: ";
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    BFS(0);

    return 0;
}
