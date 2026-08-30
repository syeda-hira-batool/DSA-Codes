#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int n){ //O(n^2) (time complexity)
	int i, j;
	for(i=0; i<n-1; i++){ //1*n
		bool isSwap = false;
		for(j=0; j<n-i-1; j++){ //n*n
			if(arr[j] > arr[j+1]){
				swap(arr[j] , arr[j+1]);
				isSwap = true;
			}
			
		}
		if(isSwap == false){ //condition: if array is aleady sorted!
			return;
		}
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
	bubbleSort(arr , size);
	printArray(arr, size);
	return 0;
	
}
