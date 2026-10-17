#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high) {

    int pivot = arr[high]; //choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) { //checking elements smaller than pivot

        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1]; //placing pivot at correct position
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if (low < high) { //base case

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1); //sorting left side
        quickSort(arr, pivotIndex + 1, high); //sorting right side
    }
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n]; 

    for (int i = 0; i < n; i++) {
    	cout << "Enter element " << i+1 << " of the array: " << endl;
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr, n);



    return 0;
}

