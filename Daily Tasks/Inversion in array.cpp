#include <iostream>
using namespace std;

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversion = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            inversion += mid - i + 1;
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inversion;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inversion = 0;

    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    inversion += mergeSort(arr, temp, left, mid);
    inversion += mergeSort(arr, temp, mid + 1, right);

    inversion += merge(arr, temp, left, mid, right);

    return inversion;
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "N must be positive." << endl;
        return 0;
    }

    int* arr = new int[n];
    int* temp = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    long long total = mergeSort(arr, temp, 0, n - 1);

    cout << "Total inversions: " << total << endl;

    delete[] arr;
    delete[] temp;

    return 0;
}

