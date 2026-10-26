#include <iostream>
using namespace std;

//(a): 

int insert(int heap[], int n, int key) {
    heap[n] = key;
    int i = n;
    n++;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int parent = (i - 1) / 2;

        swap(heap[i], heap[parent]);
        i = parent;
    }

    return n;
}

int extractMin(int heap[], int &n) {
    if (n == 0) {
        cout << "heap is empty!" << endl;
        return -1;
    }

    int minValue = heap[0];

    heap[0] = heap[n - 1];
    n--;

    int i = 0;

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int small = i;

        if (left < n && heap[left] < heap[small]) {
            small = left;
        }

        if (right < n && heap[right] < heap[small]) {
            small = right;
        }

        if (small == i) {
            break;
        }

        swap(heap[i], heap[small]);
        i = small;
    }

    return minValue;
}

void decreaseKey(int heap[], int n, int index, int newKey) {
    if (index < 0 || index >= n || newKey > heap[index]) {
        cout << "Invalid decreaseKey operation!" << endl;
        return;
    }

    heap[index] = newKey;

    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {

        int parent = (index - 1) / 2;

        swap(heap[index], heap[parent]);
        index = parent;
    }
}

//decreaseKey only shift up because decreasing a node's value is against the rules of 
//min-heap property with its parent, but not with its children.

void display(int heap[], int n) {
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
	int n = 10;
    int heap[n] = {5, 11, 8, 14, 17, 9, 12, 20, 16, 19};
    

    cout << "Initial heap: ";
    display(heap, n);

    //(b):
    n = insert(heap, n, 6);
    cout << "After inserting 6: ";
    display(heap, n);

    n = insert(heap, n, 4);
    cout << "After inserting 4: ";
    display(heap, n);

    //(c):
    cout << "Extracted minimum: " << extractMin(heap, n) << endl;
    cout << "heap after first extraction: ";
    display(heap, n);

    cout << "Extracted minimum: " << extractMin(heap, n) << endl;
    cout << "heap after second extraction: ";
    display(heap, n);

    //(d): 
    decreaseKey(heap, n, 7, 3);

    cout << "After decreaseKey at index 7: ";
    display(heap, n);

    return 0;
}

