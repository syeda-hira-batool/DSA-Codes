#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
	
	//Average: O(loglog n) for uniformly distributed values.
	//Worst: O(n)

    int low = 0, high = n - 1;

    while (low <= high &&
           key >= arr[low] && key <= arr[high]) {

        if (arr[low] == arr[high]) {
            if (arr[low] == key) {
                return low;
            }
            return -1;
        }

        int pos = low + (double)(key - arr[low]) * (high - low)/ (arr[high] - arr[low]);

        if (arr[pos] == key) {
            return pos; //element found
        }
        else if (arr[pos] < key) {
            low = pos + 1; //search right side
        }
        else {
            high = pos - 1; //search left side
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

    int result = interpolationSearch(arr, n, key);

    if (result != -1) {
        cout << "Found at index " << result;
    }
    else {
        cout << "Not found";
    }

    return 0;
}

