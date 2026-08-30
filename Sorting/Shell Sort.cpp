#include <iostream>
using namespace std;

void shellSort(int arr[], int n) { // O(n^2) worst case

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {

            int curr = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > curr) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = curr;
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

    shellSort(arr, size);

    printArray(arr, size);

    return 0;

}
