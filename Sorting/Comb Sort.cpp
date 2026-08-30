#include <iostream>
using namespace std;

void combSort(int arr[], int n) {

    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {

        // Reduce the gap
        gap = gap / 1.3;

        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        // Compare elements with the current gap
        for (int i = 0; i + gap < n; i++) {

            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {

    int arr[] = {4, 1, 5, 2, 3};
    int size = 5;

    printArray(arr, size);

    combSort(arr, size);

    printArray(arr, size);

    return 0;
}
