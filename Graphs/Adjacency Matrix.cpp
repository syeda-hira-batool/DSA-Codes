#include <iostream>
using namespace std;

class Graph {
private:
    int** adj;
    int vertices;

public:

    Graph(int v) {
        vertices = v;

        adj = new int*[vertices];

        for (int i = 0; i < vertices; i++) {
            adj[i] = new int[vertices];

            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0;
            }
        }
    }
	
	//for undirected graphs
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;  //remove this if directed graph
    }

    void printMatrix() {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adj[i];
        }

        delete[] adj;
    }
};

int main() {

    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    int u, w;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> w;

        g.addEdge(u, w);
    }

    g.printMatrix();

    return 0;
}

