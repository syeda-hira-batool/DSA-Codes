#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

// Node for Priority Queue
class Node {
public:
    int vertex;
    int distance;

    Node() {  
        vertex = 0;
        distance = 0;
    }

    Node(int v, int d) {
        vertex = v;
        distance = d;
    }
};

// Dynamic Priority Queue (Min Heap)
class PriorityQueue {
private:
    Node* heap;
    int capacity;
    int size;

    void swap(Node &a, Node &b) {
        Node temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent].distance > heap[index].distance) {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size &&
                heap[left].distance < heap[smallest].distance)
                smallest = left;

            if (right < size &&
                heap[right].distance < heap[smallest].distance)
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

    void resize() {
        capacity *= 2;

        Node* newHeap = new Node[capacity];

        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }

        delete[] heap;
        heap = newHeap;
    }

public:
    PriorityQueue() {
        capacity = 5;
        size = 0;
        heap = new Node[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int vertex, int distance) {
        if (size == capacity) {
            resize();
        }

        heap[size] = Node(vertex, distance);
        heapifyUp(size);
        size++;
    }

    Node dequeue() {
        Node minNode = heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }

        return minNode;
    }
};

// Dijkstra Algorithm
void dijkstra(int graph[MAX][MAX], int vertices, int source) {

    int* dist = new int[vertices];
    bool* visited = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    PriorityQueue pq;

    dist[source] = 0;
    pq.enqueue(source, 0);

    while (!pq.isEmpty()) {

        Node current = pq.dequeue();

        int u = current.vertex;

        if (visited[u])
            continue;

        visited[u] = true;

        for (int v = 0; v < vertices; v++) {

            if (graph[u][v] != 0 && !visited[v]) {

                int weight = graph[u][v];

                if (dist[u] != INT_MAX &&
                    dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;

                    pq.enqueue(v, dist[v]);
                }
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << " : ";

        if (dist[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }

    delete[] dist;
    delete[] visited;
}

int main() {

    int vertices;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    int graph[MAX][MAX] = {0};

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, vertices, source);

    return 0;
}

