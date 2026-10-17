#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) { //Time complexity: O(log n)

    int low = 0, high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; //element found
        }
        else if (arr[mid] < key) {
            low = mid + 1; //search right half
        }
        else {
            high = mid - 1; //search left half
        }
    }

    return -1;
}

int main() {

    int n, key;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        cout << "Found at index " << result;
    }
    else {
        cout << "Not found";
    }

    return 0;
}

