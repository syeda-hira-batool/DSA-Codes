#include<iostream>
using namespace std;

void selectionSort(int arr[] , int n){ //O(n^2) (time complexity)
	int i,j;
	for(i=0; i<n-1; i++){ //unsorted part sorting
		int smallestIndex = i;
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[smallestIndex]){
				smallestIndex = j;
			}
		}
	swap(arr[i] , arr[smallestIndex]);
	}
}

void printArray(int arr[] , int n){
	int i;
	for(i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	
	int arr[] = {4,1,5,2,3};
	int size = 5;
	printArray(arr, size);
	selectionSort(arr , size);
	printArray(arr, size);
	return 0;
	
}

