#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++){ //copy elements to temporary array
    	L[i] = arr[left + i];
	}
	
    for (int j = 0; j < n2; j++){//copy elements to temporary array
    	R[j] = arr[mid + 1 + j];
	}
        
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) { //merging 2 sorted arrays
    
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } 
        
		else {
            arr[k] = R[j];
            j++;
        }
        
        k++;
    }

    while (i < n1) { //copying l elements
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) { //copying R elements
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
	
    if (left >= right){
    	return;
	}

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void display(int arr[] , int n){
	for(int i=0; i<n; i++){
		cout << arr[i]  << " ";
	}
	cout << endl;
}

int main() {
	
	int n;
	cout<< "Enter the number of elements in the array: " << endl;
	cin >> n;
	int arr[n];
	
    n = sizeof(arr) / sizeof(arr[0]);
    int ele;
    
    for(int i=0; i<n; i++){
    	cout << "Enter the element " << i+1 << " of the array: " << endl;
    	cin >> ele;
    	arr[i] = ele;
	}
	
	cout << "Original array: ";
    display(arr,n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr,n);

    return 0;
}

