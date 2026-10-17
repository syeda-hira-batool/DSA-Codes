#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) { //Time complexity: O(n)

    for (int i = 0; i < n; i++) { //checking each element
        if (arr[i] == key) {
            return i; //element found
        }
    }

    return -1; //element not found
}

int main() {

    int n, key;
    cout << "Enter size: ";
    cin >> n;

    int arr[n]; 

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        cout << "Found at index " << result;
    }
    else {
        cout << "Not found";
    }

    return 0;
}

