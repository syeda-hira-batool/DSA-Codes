#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bucketSort(int arr[], int n) {

    int buckets[10][100] = {0};
    int count[10] = {0};

    for (int i = 0; i < n; i++) { //placing elements into buckets

        int bucketIndex = arr[i] / 10;

        if (bucketIndex > 9) {
            bucketIndex = 9;
        }

        buckets[bucketIndex][count[bucketIndex]] = arr[i];
        count[bucketIndex]++;
    }

    for (int i = 0; i < 10; i++) { //sorting each bucket

        for (int j = 0; j < count[i] - 1; j++) {
            for (int k = 0; k < count[i] - j - 1; k++) {

                if (buckets[i][k] > buckets[i][k + 1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    int index = 0;

    for (int i = 0; i < 10; i++) { //combining buckets

        for (int j = 0; j < count[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
    	cout << "Enter the array element " << i+1 << " :" << endl;
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}

